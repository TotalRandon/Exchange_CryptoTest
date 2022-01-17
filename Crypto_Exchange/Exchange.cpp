#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



using namespace std;

string endereco_btc[10], endereco_eth[10], endereco_ltc[10], endereco_ada[10];
double BTC = 61500, ETH = 4500, LTC = 220, ADA = 2.1;

// =================== Exchange ===================

int SorteiaPreco(double b) // Sorteia o valor da criptomoeda
{
    int a;

    srand(time(NULL)); //É para gerar um numero aleatorio todas as vezes que abrir o programa
    a = rand() % 100; // Vai gerar o numero entre 0 e 99
    if (a >= 1 && a <= 10)
    {
        b = b - (b / 8);
    }
    else
    {
        if (a > 10 && a <= 20)
        {
            b = b - (b / 16);
        }
        else
        {
            if (a > 20 && a <= 30)
            {
                b = b - (b / 32);
            }
            else
            {
                if (a > 30 && a <= 40)
                {
                    b = b - (b / 64);
                }
                else
                {
                    if (a > 40 && a <= 50)
                    {
                        b = b - (b / 128);
                    }
                    else
                    {
                        if (a > 50 && a <= 60)
                        {
                            b = b + (b / 8);
                        }
                        else
                        {
                            if (a > 60 && a <= 70)
                            {
                                b = b + (b / 16);
                            }
                            else
                            {
                                if (a > 70 && a <= 80)
                                {
                                    b = b + (b / 32);
                                }
                                else
                                {
                                    if (a > 80 && a <= 90)
                                    {
                                        b = b + (b / 64);
                                    }
                                    else
                                    {
                                        b = b + (b / 128);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return b;
}

int main()
{
    // saldo = USD // depo = BRL
    double btc, eth, ltc, ada;
    double saldo = 100, depo, saque, compra, venda, saqueC, depoC;
    double tarifasaque = 2.50;
    int a;

    system("clear");
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                                " << endl;
    cout << "            _____                 _                                         ____                                 " << endl;
    cout << "           | ____| __  __   ___  | |__     __ _   _ __     __ _    ___     / ___|    _       _                  " << endl;
    cout << "           |  _|   `    /  / __| | '_  `  / _` | | '_     / _` |  / _     | |      _| |_   _| |_                " << endl;
    cout << "           | |___   >  <  | (__  | | | | | (_| | | | | | | (_| | |  __/   | |___  |_   _| |_   _|               " << endl;
    cout << "           |_____| /_/|_     __| |_| |_|    _,_| |_| |_|   __, |   ___|     ____|   |_|     |_|                 " << endl;
    cout << "                                                           |___/                                                " << endl;
    cout << "                                                                                                                " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    sleep(5);
    while (1)
    {
        system("clear");
        cout << endl;
        cout << fixed;
        cout.precision(6);
        cout << "-----------------------------------------------------------" << endl;
        cout << "Bem vindo ao simulador de Exchange e BlockChain em C++"
             << "       Saldo: " << saldo << " USD" << endl;
        cout << endl;
        cout << "Digite 1 para comprar BTC "
             << "                                   BTC: " << btc << endl;
        cout << "Digite 2 para Vender  BTC "
             << "                                   ETH: " << eth << endl;
        cout << "Digite 3 para comprar ETH "
             << "                                   LTC: " << ltc << endl;
        cout << "Digite 4 para Vender  ETH "
             << "                                   ADA: " << ada << endl;
        cout << "Digite 5 para comprar LTC" << endl;
        cout << "Digite 6 para Vender  LTC" << endl;
        cout << "Digite 7 para comprar ADA" << endl;
        cout << "Digite 8 para vender  ADA" << endl;
        cout << "Digite 9 para depositar seu Dinhero [BRL --> USD]" << endl;
        cout << "Digite 10 para sacar seu Dinhero [USD --> BRL]" << endl;
        cout << "Digite 11 para depositar suas criptomoedas" << endl;
        cout << "Digite 12 para sacar suas criptomoedas" << endl;
        cout << "Digite 13 para ver seus endereços" << endl;
        cout << "Digite 14 para ir para Carteira Virtual" << endl;
        cout << "Digite 0 para sair" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << endl;
        cin >> a;
        cout << endl;
        switch (a)
        {
        case 1:
            if (saldo < 10) ///////////////////////////////// BTC compra /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << "  Voce não possui saldo suficiente!   " << endl;
                cout << "          Minimo de 10 USD            " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                BTC = SorteiaPreco(BTC);
                cout << "------------------------------------------------" << endl;
                cout << "1 - BTC: " << BTC << "     Saldo(USD): " << saldo << endl;
                cout << endl;
                cout << "Comprar: ";
                cin >> compra;
                cout << "------------------------------------------------" << endl;
                sleep(1);
                if (compra > saldo)
                {
                    cout << endl;
                    cout << "Saldo invalido!" << endl;
                    sleep(3);
                }
                else
                {
                    if (compra == 0)
                    {
                        break;
                    }
                    else
                    {
                        if (compra < 10)
                        {
                            cout << endl;
                            cout << "O minimo para transacionar são 10 USD!" << endl;
                            cout << endl;
                            sleep(3);
                        }
                        else
                        {
                            saldo = saldo - compra;     // descontabiliza o valor do saldo em relação a compra
                            BTC = 1 / BTC;              // valor do BTC a 1 dolar
                            btc = (compra * BTC) + btc; // Conta para contabilizar no saldo do btc
                            compra = 0;                 // reseta variavel para compra de cripto
                            BTC = 0;                    // reseta variavel de compraração de valor do BTC
                            BTC = 61500;                // retorna valor principal
                            BTC = SorteiaPreco(BTC);    // resorteia na segunda vez
                        }
                    }
                }
            }
            break;

        case 2:
            if (btc == 0) ///////////////////////////////// BTC venda /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << " Voce não possui Bitcoins suficientes " << endl;
                cout << "       para vender no moemento!       " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                BTC = SorteiaPreco(BTC);
                cout << "----------------------------------------" << endl;
                cout << "1 - BTC: " << BTC << "     Saldo(BTC): " << btc << endl;
                cout << endl;
                cout << "Vender: ";
                cin >> venda;
                cout << "--------------------------------" << endl;
                sleep(1);
                if (btc < 0.0001)
                {
                    cout << endl;
                    cout << "Minimo para transacionar são de 0.0001 BTC!" << endl;
                    cout << endl;
                    sleep(3);
                }
                else
                {
                    if (venda == 0 || venda > btc)
                    {
                        break;
                    }
                    else
                    {
                        saldo = (btc * BTC) + saldo;
                        btc = btc - venda;
                        venda = 0;
                        BTC = 0;
                        BTC = 61500;
                        BTC = SorteiaPreco(BTC);
                    }
                }
            }
            break;

        case 3:
            if (saldo < 10) ///////////////////////////////// BTC compra /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << "  Voce não possui saldo suficiente!   " << endl;
                cout << "          Minimo de 10 USD            " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                ETH = SorteiaPreco(ETH);
                cout << "------------------------------------------------" << endl;
                cout << "1 - ETH: " << ETH << "     Saldo(USD): " << saldo << endl;
                cout << endl;
                cout << "Comprar: ";
                cin >> compra;
                cout << "------------------------------------------------" << endl;
                sleep(1);
                if (compra > saldo)
                {
                    cout << endl;
                    cout << "Saldo invalido!" << endl;
                    sleep(3);
                }
                else
                {
                    if (compra == 0)
                    {
                        break;
                    }
                    else
                    {
                        if (compra < 10)
                        {
                            cout << endl;
                            cout << "O minimo para transacionar são 10 USD!" << endl;
                            cout << endl;
                            sleep(3);
                        }
                        else
                        {
                            saldo = saldo - compra;     // descontabiliza o valor do saldo em relação a compra
                            ETH = 1 / ETH;              // valor do BTC a 1 dolar
                            eth = (compra * ETH) + eth; // Conta para contabilizar no saldo do btc
                            compra = 0;                 // reseta variavel para compra de cripto
                            ETH = 0;                    // reseta variavel de compraração de valor do BTC
                            ETH = 4500;                 // retorna valor principal
                            ETH = SorteiaPreco(ETH);    // resorteia na segunda vez
                        }
                    }
                }
            }
            break;

        case 4:
            if (eth == 0) ///////////////////////////////// ETH venda /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << " Voce não possui Ethereums suficientes" << endl;
                cout << "       para vender no moemento!       " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                ETH = SorteiaPreco(ETH);
                cout << "----------------------------------------" << endl;
                cout << "1 - ETH: " << ETH << "     Saldo(ETH): " << eth << endl;
                cout << endl;
                cout << "Vender: ";
                cin >> venda;
                cout << "--------------------------------" << endl;
                sleep(1);
                if (eth < 0.01)
                {
                    cout << endl;
                    cout << "Minimo para transacionar são de 0.01 ETH!" << endl;
                    cout << endl;
                    sleep(3);
                }
                else
                {
                    if (venda == 0 || venda > eth)
                    {
                        break;
                    }
                    else
                    {
                        saldo = (eth * ETH) + saldo;
                        eth = eth - venda;
                        venda = 0;
                        ETH = 0;
                        ETH = 4500;
                        ETH = SorteiaPreco(ETH);
                    }
                }
            }
            break;

        case 5:
            if (saldo < 10) ///////////////////////////////// LTC compra /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << "  Voce não possui saldo suficiente!   " << endl;
                cout << "          Minimo de 10 USD            " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                LTC = SorteiaPreco(LTC);
                cout << "--------------------------------------" << endl;
                cout << "1 - LTC: " << LTC << "     Saldo: " << saldo << endl;
                cout << endl;
                cout << "Comprar: ";
                cin >> compra;
                cout << "--------------------------------------" << endl;
                sleep(1);
                if (compra > saldo)
                {
                    cout << endl;
                    cout << "Saldo invalido!" << endl;
                    sleep(3);
                }
                else
                {
                    if (compra == 0)
                    {
                        break;
                    }
                    else
                    {
                        if (compra < 10)
                        {
                            cout << endl;
                            cout << "O minimo para transacionar são 10 USD!" << endl;
                            cout << endl;
                            sleep(3);
                        }
                        else
                        {
                            saldo = saldo - compra;     // descontabiliza o valor do saldo em relação a compra
                            LTC = 1 / LTC;              // valor do BTC a 1 dolar
                            ltc = (compra * LTC) + ltc; // Conta para contabilizar no saldo do btc
                            compra = 0;                 // reseta variavel para compra de cripto
                            LTC = 0;                    // reseta variavel de compraração de valor do BTC
                            LTC = 220;                  // retorna valor principal
                            LTC = SorteiaPreco(LTC);    // resorteia na segunda vez
                        }
                    }
                }
            }
            break;

        case 6:
            if (ltc == 0) ///////////////////////////////// LTC venda /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << " Voce não possui Litecoins suficientes" << endl;
                cout << "       para vender no momento!        " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                LTC = SorteiaPreco(LTC);
                cout << "----------------------------------------" << endl;
                cout << "1 - LTC: " << LTC << "     Saldo(LTC): " << ltc << endl;
                cout << endl;
                cout << "Vender: ";
                cin >> venda;
                cout << "--------------------------------" << endl;
                sleep(1);
                if (ltc < 0.05)
                {
                    cout << endl;
                    cout << "Minimo para transacionar são de 0.05 LTC!" << endl;
                    cout << endl;
                    sleep(3);
                }
                else
                {
                    if (venda == 0 || venda > ltc)
                    {
                        break;
                    }
                    else
                    {
                        saldo = (ltc * LTC) + saldo;
                        ltc = ltc - venda;
                        venda = 0;
                        LTC = 0;
                        LTC = 4500;
                        LTC = SorteiaPreco(LTC);
                    }
                }
            }
            break;

        case 7:
            if (saldo < 10) ///////////////////////////////// ADA compra /////////////////////////////////
            {
                cout << "--------------------------------------" << endl;
                cout << "  Voce não possui saldo suficiente!   " << endl;
                cout << "          Minimo de 10 USD            " << endl;
                cout << "--------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                ADA = SorteiaPreco(ADA);
                cout << "--------------------------------------" << endl;
                cout << "1 - ADA: " << ADA << "     Saldo: " << saldo << endl;
                cout << endl;
                cout << "Comprar: ";
                cin >> compra;
                cout << "--------------------------------------" << endl; // ada bugada
                sleep(1);
                if (compra > saldo)
                {
                    cout << endl;
                    cout << "Saldo invalido!" << endl;
                    sleep(3);
                }
                else
                {
                    if (compra == 0)
                    {
                        break;
                    }
                    else
                    {
                        if (compra < 10)
                        {
                            cout << endl;
                            cout << "O minimo para transacionar são 10 USD!" << endl;
                            cout << endl;
                            sleep(3);
                        }
                        else
                        {
                            saldo = saldo - compra;     // descontabiliza o valor do saldo em relação a compra
                            ADA = 1 / ADA;              // valor do BTC a 1 dolar
                            ada = (compra * ADA) + ada; // Conta para contabilizar no saldo do btc
                            compra = 0;                 // reseta variavel para compra de cripto
                            ADA = 0;                    // reseta variavel de compraração de valor do BTC
                            ADA = 2.1;                  // retorna valor principal
                            ADA = SorteiaPreco(ADA);    // resorteia na segunda vez
                        }
                    }
                }
            }
            break;

        case 8:
            if (ada == 0) /////////////////////////////////// ADA venda /////////////////////////////////
            {
                cout << "---------------------------------------" << endl;
                cout << "Voce não possui Ada Cardano suficiente " << endl;
                cout << "        para vender no momento!        " << endl;
                cout << "---------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                ADA = SorteiaPreco(ADA);
                cout << "----------------------------------------" << endl;
                cout << "1 - ADA: " << ADA << "     Saldo(ADA): " << ada << endl;
                cout << endl;
                cout << "Vender: ";
                cin >> venda;
                cout << "--------------------------------" << endl;
                sleep(1);
                if (eth < 10)
                {
                    cout << endl;
                    cout << "Minimo para transacionar são de 10 ADA!" << endl;
                    cout << endl;
                    sleep(3);
                }
                else
                {
                    if (venda == 0 || venda > ada)
                    {
                        break;
                    }
                    else
                    {
                        saldo = (ada * ADA) + saldo;
                        ada = ada - venda;
                        venda = 0;
                        ADA = 0;
                        ADA = 2.1;
                        ADA = SorteiaPreco(ADA);
                    }
                }
            }
            break;

        case 9: ///////////////////////////////// Deposito --> [BRL - USD] /////////////////////////////////
            cout << "------------------------------------" << endl;
            cout << "  Area de deposito de BRL para USD  " << endl;
            cout << endl;
            cout << "1 BRL = 0.18 usd --> 1 USD = 5.46 R$" << endl;
            cout << "------------------------------------" << endl;
            cout << endl;
            cin >> depo;
            if (depo > 20000)
            {
                cout << endl;
                cout << "Limite maximo de deposito é de R$ 20.000!" << endl;
                sleep(2);
            }
            else
            {
                depo = depo / 5.46;
                saldo = saldo + depo;
                sleep(3);
                cout << "Deposito realizado com sucesso!" << endl;
                cout << "Valor do deposito: " << depo << endl;
                sleep(3);
            }
            break;

        case 10: ///////////////////////////////// Saque --> [USD - BRL] /////////////////////////////////
            cout << "------------------------------------" << endl;
            cout << "   Area de saque de USD para BRL    " << endl;
            cout << endl;
            cout << "1 BRL = 0.18 usd --> 1 USD = 5.46 R$" << endl;
            cout << "------------------------------------" << endl;
            cout << endl;
            cin >> saque;
            if (saque > saldo || saque < 10)
            {
                cout << endl;
                cout << "Não é possivel sacar esse valor!" << endl;
                cout << endl;
                sleep(3);
            }
            else
            {
                cout << fixed;
                cout.precision(2);
                cout << endl;
                saldo = saldo - saque;
                saque = saque - tarifasaque;
                saque = saque * 5.46;
                sleep(2);
                cout << "Saque realizado com sucesso!" << endl;
                cout << "Valor do saque:    " << saque << " R$" << endl;
                cout << "Tarifa de saque:   " << tarifasaque << " R$" << endl;
                cout << endl;
                sleep(5);
            }

            break;

        case 11: ///////////////////////////////// deposito de criptomoedas /////////////////////////////////
            break;

        case 12: ///////////////////////////////// saque de criptomoedas /////////////////////////////////
            cout << "---------------------------------------" << endl;
            cout << "     Area de saque de criptomoedas     " << endl;
            cout << endl;
            if (btc == 0 && eth == 0 && ltc == 0 && ada == 0)
            {
                cout << "Voce não possui critomoedas no momento!" << endl;
                cout << "---------------------------------------" << endl;
                sleep(3);
            }
            else
            {
                cout << "---------------------------------------" << endl;
                cout << "     Area de saque de criptomoedas     " << endl;
                cout << endl;
                cout << "1 - BTC: " << btc << endl;
                cout << "2 - ETH: " << eth << endl;
                cout << "3 - LTC: " << ltc << endl;
                cout << "4 - ADA: " << ada << endl;
                cout << endl;
                cout << "Escolha uma criptomoeda deseja sacar:  ";
                // cin >> saqueC;
            }
            break;

        case 13: ///////////////////////////////// ver lista de endereços criados na exchange /////////////////////////////////
            break;

        case 14: ///////////////////////////////// ir para carteira virtual /////////////////////////////////
            break;

        case 0:
            cout << "Saindo do programa..." << endl;
            sleep(3);
            return 0;
            break;

        default:
            cout << "Numero invalido!" << endl;
            sleep(3);
            break;
        }
    }
    return 0;
}