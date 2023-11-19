#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int faktorial(int n) {
    if (n <= 1)
        return 1;
    return n * faktorial(n - 1);
}

double rataRata(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / n;
}

int modus(int arr[], int n) {
    int maxCount = 0, mode = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

double median(int arr[], int n) {
    sort(arr, arr + n);
    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
}

int deretAritmatika(int a, int b, int n) {
    return a + (n - 1) * b;
}

int jumlahDeretAritmatika(int a, int b, int n) {
    return n * (2 * a + (n - 1) * b) / 2;
}

int nilaiTengah(int a, int n) {
    return (a + deretAritmatika(a, 1, n)) / 2;
}

int main() {
    int menu;
    int n;
    int fact;
    int subMenu;
    int a, b;
    int Un;
    int Sn;
    int Ut;

    do {
		cout << endl << "============================= Rumus Faktorial, Statistika, & Deret Aritmatika ==============================" << endl;
        cout << "Pilih menu:" << endl;
        cout << "1. Faktorial" << endl;
        cout << "2. Statistika" << endl;
        cout << "3. Deret Aritmatika" << endl;
        cout << "0. Keluar" << endl;
        cin >> menu;

        switch (menu) {
			// Faktorial
            case 1:
                cout << "Masukkan bilangan untuk faktorial: ";
                cin >> n;
                fact = faktorial(n);
                cout << n << "! = " << fact << endl;
                break;

		// Statistika
            case 2:
                cout << "Pilih menu statistika:" << endl;
                cout << "1. Rata-rata" << endl;
                cout << "2. Modus" << endl;
                cout << "3. Median" << endl;
                cin >> subMenu;
                if (subMenu == 1) {
                    int banyakBilangan;
                    cout << "Masukkan jumlah bilangan: ";
                    cin >> banyakBilangan;
                    int arr[banyakBilangan];
                    cout << "Masukkan " << banyakBilangan << " bilangan: ";
                    for (int i = 0; i < banyakBilangan; i++) {
                        cin >> arr[i];
                    }
                    double rata_rata = rataRata(arr, banyakBilangan);
                    cout << "Rata-rata: " << rata_rata << endl;
                } else if (subMenu == 2) {
                    int banyakBilangan;
                    cout << "Masukkan jumlah bilangan: ";
                    cin >> banyakBilangan;
                    int arr[banyakBilangan];
                    cout << "Masukkan " << banyakBilangan << " bilangan: ";
                    for (int i = 0; i < banyakBilangan; i++) {
                        cin >> arr[i];
                    }
                    int mod = modus(arr, banyakBilangan);
                    cout << "Modus: " << mod << endl;
                } else if (subMenu == 3) {
                    int banyakBilangan;
                    cout << "Masukkan jumlah bilangan: ";
                    cin >> banyakBilangan;
                    int arr[banyakBilangan];
                    cout << "Masukkan " << banyakBilangan << " bilangan: ";
                    for (int i = 0; i < banyakBilangan; i++) {
                        cin >> arr[i];
                    }
                    double med = median(arr, banyakBilangan);
                    cout << "Median: " << med << endl;
                } else {
                    cout << "Pilihan menu statistika tidak valid!" << endl;
                }
                break;

			// Deret Aritmatika
            case 3:
                cout << "Pilih menu deret aritmatika:" << endl;
                cout << "1. Un" << endl;
                cout << "2. Sn" << endl;
                cout << "3. Ut" << endl;
                cout << "4. Un = Sn - S(n-1)" << endl;
                cin >> subMenu;
                cout << "Masukkan nilai a (suku pertama): ";
                cin >> a;
                cout << "Masukkan nilai b (selisih): ";
                cin >> b;
                cout << "Masukkan nilai n (bilangan ke-berapa): ";
                cin >> n;
                if (subMenu == 1) {
                    Un = deretAritmatika(a, b, n);
                    cout << "Un = " << Un << endl;
                } else if (subMenu == 2) {
                    Sn = jumlahDeretAritmatika(a, b, n);
                    cout << "Sn = " << Sn << endl;
                } else if (subMenu == 3) {
                    Ut = nilaiTengah(a, n);
                    cout << "Ut = " << Ut << endl;
                } else if (subMenu == 4) {
                    if (n > 1) {
                        int S_n_minus_1 = jumlahDeretAritmatika(a, b, n - 1);
                        Un = Sn - S_n_minus_1;
                        cout << "Un = Sn - S(n-1) = " << Un << endl;
                    } else {
                        cout << "Untuk n=1, rumus Un = Sn - S(n-1) tidak berlaku." << endl;
                    }
                } else {
                    cout << "Pilihan menu deret aritmatika tidak valid!" << endl;
                }
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan menu tidak valid!" << endl;
                break;
        }
    } while (menu != 0);

    return 0;
}