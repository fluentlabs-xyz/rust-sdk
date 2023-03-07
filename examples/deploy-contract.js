const Web3 = require('web3');

const DEPLOYER_PRIVATE_KEY = '40b98b34b4796aaf2315baf772d7cdcf2d5eafe6fe11ee751ebd40853874b30b';
const BYTECODE = '0061736d0100000001090260027f7f0060000002130103656e760b5f65766d5f72657475726e00000302010105030100110619037f01418080c0000b7f0041a081c0000b7f0041a081c0000b072c04066d656d6f72790200046d61696e00010a5f5f646174615f656e6403010b5f5f686561705f6261736503020a0e010c00418080c00041a00110000b0baa010100418080c0000ba0010061736d0100000001090260027f7f0060000002130103656e760b5f65766d5f72657475726e00000302010105030100110619037f01418080c0000b7f00418c80c0000b7f00419080c0000b072c04066d656d6f72790200046d61696e00010a5f5f646174615f656e6403010b5f5f686561705f6261736503020a0d010b00418080c000410c10000b0b150100418080c0000b0c48656c6c6f2c20576f726c64';

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
    });
    const message = web3.utils.hexToAscii(result)
    console.log(`Message: "${message}"`)

    const signedTransaction1 = await web3.eth.accounts.signTransaction({
        to: contractAddress,
        gas: 10_000_000,
    }, DEPLOYER_PRIVATE_KEY)
    const receipt1 = await web3.eth.sendSignedTransaction(signedTransaction1.rawTransaction);
    console.log(`Receipt: ${JSON.stringify(receipt1, null, 2)}`)

    const latestMinedBlockNumber = await web3.eth.getBlockNumber();
    console.log(`Latest block number: ${latestMinedBlockNumber}`);
}

main().then(console.log).catch(console.error);