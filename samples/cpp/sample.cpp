// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWString.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    

    TWHDWallet* walletImp = nullptr;
    
        // Create a new multi-coin HD wallet, with new recovery phrase (mnemonic)
        

        // Alternative: Import wallet with existing recovery phrase (mnemonic)
        cout << "Importing an HD wallet from earlier ... ";
        auto secretMnemonic = TWStringCreateWithUTF8Bytes("ripple scissors kick mammal hire column oak again sun offer wealth tomorrow wagon turn fatal");
        walletImp = TWHDWalletCreateWithMnemonic(secretMnemonic, TWStringCreateWithUTF8Bytes(""));
       
        
    

    
        // coin type: we use Ethereum
        const TWCoinType coinType = TWCoinType::TWCoinTypeEthereum; // TWCoinTypeBitcoin, TWCoinTypeEthereum
       

        // Derive default address.
        cout << "Obtaining default address ... ";
        string address = TWStringUTF8Bytes(TWHDWalletGetAddressForCoin(walletImp, coinType));
        cout << "Default address:          '" << address << "'" << endl;

        
    cout << "Bye!" << endl;
    TWHDWalletDelete(walletImp);
}
