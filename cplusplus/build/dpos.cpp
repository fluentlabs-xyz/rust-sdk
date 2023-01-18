//
// Created by Vladislav Lazarev on 2019-02-28.
//

#include <wasmsdk/wasmsdk.h>

using namespace wasmsdk;

struct VotesKey {
    address candidate;
    address voter;

    VotesKey(address candidate, address voter) : candidate(candidate), voter(voter) {}
};
wasmsdk_ABI_STRUCT(VotesKey, candidate, voter)

storage<VotesKey, uint256> votes{ "voteOf"_m };
storage_array<address> candidates{ "candidates"_m };
storage_array<address> validators{ "validators"_m };
uint32 PREVIOUS_ELECTION = 0;
storage<address, uint256> freezing_balances{ "freezingBalanceOf"_m};
storage<address, bool> are_validators{ "isValidator"_m };

wasmsdk_ABI("vote(address,uint256)", "void")
static void vote(address candidate, uint256 voteBalance) {
    votes[VotesKey(candidate, get_sender())] += voteBalance;
}


wasmsdk_ABI("voteOf(address,address)", "void")
static uint256 vote_of(address candidate, address voter) {
    return votes[VotesKey(candidate, voter)];
}


wasmsdk_ABI("isValidator(address)", "bool")
static bool is_validator(address candidate) {
    return are_validators[candidate];
}



wasmsdk_ABI("freezingBalanceOf(address)", "uint256")
static uint256 freezing_balance_of(address candidate) {
    return freezing_balances[candidate];
}

wasmsdk_ABI("becomeCandidate()", "bool")
static bool become_candidate() {
    address sender = get_sender();
    candidates.push(sender);
    if (freezing_balances[sender] != uint256(0)) {
        return false;
    }
    freezing_balances[sender] = get_transferred_funds(0);
    return true;
}


wasmsdk_ABI("freezeBalance()", "bool")
static bool freeze_balance() {

    address sender = get_sender();
    if (freezing_balance_of(sender) == uint256(0)) {
        return false;
    }
    freezing_balances[sender] += get_transferred_funds(0);
    return true;
}

wasmsdk_ABI("returnValue(uint256)", "bool")
static bool return_value(uint256 value) {

    address sender = get_sender();
    assert(freezing_balance_of(sender) < value || is_validator(sender));

    freezing_balances[sender] -= get_transferred_funds(0);
    return true;
}



wasmsdk_ABI("reelection(array<address>)", "bool")
static bool reelection(array<address> new_validators) {
    uint32 block_number = get_block_number(0);
    assert(block_number < PREVIOUS_ELECTION + 12);

    PREVIOUS_ELECTION = block_number;
    for (uint32 i = 0; i < validators.length(); ++i) {
        validators[i] = new_validators[i];
    }
    candidates.clear();
    return true;
}

