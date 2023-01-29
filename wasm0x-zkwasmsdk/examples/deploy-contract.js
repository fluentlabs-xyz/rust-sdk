const Web3 = require('web3');

const DEPLOYER_PRIVATE_KEY = '40b98b34b4796aaf2315baf772d7cdcf2d5eafe6fe11ee751ebd40853874b30b';
const BYTECODE = '0061736d01000000010b0260027f7f0060017f017f02130103656e760b5f65766d5f72657475726e0000030201010405017001010105030100110619037f01418080c0000b7f0041ab81c0000b7f0041b081c0000b072c04066d656d6f72790200046d61696e00010a5f5f646174615f656e6403010b5f5f686561705f6261736503020a10010e00418080c00041ab01100041000b0bb5010100418080c0000bab010061736d01000000010b0260027f7f0060017f017f02130103656e760b5f65766d5f72657475726e0000030201010405017001010105030100110619037f01418080c0000b7f00418c80c0000b7f00419080c0000b072c04066d656d6f72790200046d61696e00010a5f5f646174615f656e6403010b5f5f686561705f6261736503020a0f010d00418080c000410c100041000b0b150100418080c0000b0c48656c6c6f2c20576f726c64';

const main = async () => {
    const web3 = new Web3('http://localhost:8545');
    console.log('Signing transaction...');
    const signedTransaction = await web3.eth.accounts.signTransaction({
        data: BYTECODE,
        gas: 10_000_000,
    }, DEPLOYER_PRIVATE_KEY)
    console.log('Sending transaction...');
    const receipt = await web3.eth.sendSignedTransaction(signedTransaction.rawTransaction);
    console.log(`Receipt: ${JSON.stringify(receipt, null, 2)}`)
    const {contractAddress} = receipt;
    const result = await web3.eth.call({
        to: contractAddress,
    })
    const message = web3.utils.hexToAscii(result)
    console.log(`Message: "${message}"`)
}

main().then(console.log).catch(console.error);