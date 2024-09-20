else if (jenisPencarian == 'H' || jenisPencarian == 'h') {
                char hurufAwal, hurufAkhir;
                cout << "Input Huruf Awal: ";
                cin >> hurufAwal;
                cout << "Input Huruf Akhir (biarkan kosong jika tidak ada): ";
                cin >> hurufAkhir;
                sistem.cariDataPasienByHurufAwal(hurufAwal, hurufAkhir);
            } else {