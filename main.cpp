#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

int sab, bd, cut, cnt;
void Shell(int array[], int n){                //сортировка Шелла
    cut = n;
    cut = cut / 2;
    while(cut > 0){
        for (int i = 0; i < n - cut; i++) {
            sab = i;
            while(sab >= 0 && array[sab] > array[sab + cut]){
                cnt = array[sab];
                array[sab] = array[sab + cut];
                array[sab + cut] = cnt;
                sab--;
            }
        }
        cut = cut / 2;
    }

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}



int main() {
    setlocale(LC_ALL, "en");
    
    while(true) {
        char number;
        cout << "\nEnter a number from 1 to 5(the number is a task in practice), 6 - idz\n";
        cin.sync();
        cin >> number;
        srand(time(0));
        int arr[100];
        int min;
        int max;
        auto start = steady_clock::now();                  // chrono
        cout << endl;
        auto end = steady_clock::now();
        auto result = duration_cast<nanoseconds>(end - start);
        
        switch (number) {

            case '1': {
                cout << "Unsorted array: " << "\n";                        // unsorted array
                start = steady_clock::now();
                for (int i = 0; i < 100; i++) {
                    arr[i] = rand() % 199 - 99;
                }

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);      // fide time unsorted array
                cout << "Time: " << result.count() << " ns" << "\n";

                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n" << "\n";


                cout << "Bubble sort: " << "\n";              // bubble sort
                start = steady_clock::now();
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < 99; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int b = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = b;
                        }
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);    // fide time sorted array(bubble sort)
                cout << "Time: " << result.count() << " ns" << "\n";
                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }

                cout << "\n" << "\n";

                start = steady_clock::now();
                for (int i = 0; i < 100; i++)                  // min and max(sorted array)
                {
                    if (arr[i + 1] < arr[i]) {
                        max = arr[i];
                    }
                    if (arr[i - 1] > arr[i]) {
                        min = arr[i];
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                cout << "Min: " << min << endl;
                cout << "Max: " << max << endl;
                cout << "Time: " << result.count() << " ns" << "\n";

                cout << "\n";

                cout << "Average value of min and max: ";     // average value of min and max(sorted array)
                float sr = (min + max) / 2;
                cout << sr << "\n";

                cout << "indexes: ";
                
                start = steady_clock::now();
                int d = 0;
                for (int i = 0; i < 100; i++) {
                    if (arr[i] == int(sr)) {
                        cout << i << " ";
                        d += 1;
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << endl << "elements: " << d << "\n";            // prints the number of indexes of all elements
                cout << "Time: " << result.count() << " ns" << "\n";

                cout << "Enter the number v: ";
                int v;                        /* Returns the number of elements in the sorted array that are
                                     less than the number V, which is initialized by the user */
                int q = 0;
                cin >> v;
                for (int i = 0; i < 100; i++)
                    if (arr[i] < v)
                        q += 1;
                cout << "less v: " << q;

                cout << "\n";

                cout << "Enter the number w: ";                /*Returns the number of elements in the sorted array that are greater
                                           than the number W, which is initialized by the user*/
                int w;
                int l = 0;
                cin >> w;
                for (int i = 0; i < 100; i++)
                    if (arr[i] < w)
                        l += 1;
                cout << "more w: " << l;

                cout << "\n";

                cout << "\n" << "\n";
                break;
            }


            case '2': {
                cout << "Unsorted array: " << "\n";
                for (int i = 0; i < 100; i++) {
                    arr[i] = rand() % 199 - 99;
                }
                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }

                cout << "\n" << "\n";

                cout << "Shaker sort: " << "\n";                          // shaker sort
                start = steady_clock::now();
                bool s = true;
                int t = 0;
                int nd = 99;
                while (s) {
                    s = false;
                    for (int i = t; i < nd; ++i) {
                        if (arr[i] > arr[i + 1]) {
                            swap(arr[i], arr[i + 1]);
                            s = true;
                        }
                    }
                    s = false;
                    nd--;
                    for (int i = nd - 1; i >= t; --i) {
                        if (arr[i] > arr[i + 1]) {
                            swap(arr[i], arr[i + 1]);
                            s = true;
                        }
                    }
                    t++;
                }

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);      // fide time sorted array(shaker sort)
                cout << "Time: " << result.count() << " ns" << "\n";

                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }

                cout << "\n";

                cout << "\n" << "\n";
                break;
            }


            case '3': {
                cout << "Unsorted array: " << "\n";
                for (int i = 0; i < 100; i++) {
                    arr[i] = rand() % 199 - 99;
                }
                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }

                cout << "\n" << "\n";

                cout << "Comb sort: " << "\n";                     // comb sort
                start = steady_clock::now();
                int a;
                int b;
                while (true) {
                    for (int i = 0; i < 99; i++) {
                        if (arr[i] > arr[i + 1]) {
                            b = arr[i + 1];
                            arr[i + 1] = arr[i];
                            arr[i] = b;
                        } else a++;
                    }
                    if (a == 99) {
                        break;
                    } else {
                        a = 0;
                    }
                }

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);     // fide time sorted array(comb sort)
                cout << "Time: " << result.count() << " ns" << "\n";

                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";

                cout << "\n" << "\n";
                break;
            }

            case '4': {
                cout << "Unsorted array: " << "\n";
                for (int i = 0; i < 100; i++) {
                    arr[i] = rand() % 199 - 99;
                }
                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }

                cout << "\n" << "\n";

                cout << "Insert sort: " << "\n";              // insert sort
                start = steady_clock::now();
                int x;
                for (int i = 0; i < 100; i++) {
                    x = arr[i];
                    int j = i;
                    while ((j > 0) && (x < arr[j - 1])) {
                        arr[j] = arr[j - 1];
                        j--;
                    }

                    arr[j] = x;
                }

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);       // fide time sorted array(insert sort)
                cout << "Time: " << result.count() << " ns" << "\n";

                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl << "\n";
                break;
            }

            case '5': {
                cout << "array: " << "\n";                  // Swaps the elements of an array whose indexes are entered by the user
                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\nEnter 2 indexes: " << "\n";
                int m, k;
                cin >> m >> k;
                cout << "\narray: " << "\n";
                start = steady_clock::now();
                int ind = arr[m];
                arr[m] = arr[k];
                arr[k] = ind;

                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);

                for (int i = 0; i < 100; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\nTime: " << result.count() << " ns\n";     // exchange rate

                cout << "\n" << "\n";
                break;
            }

            case '6': {
                cout << "array size(Shell sort):  ";
                cin >> bd;
                int *array = new int[bd];              //объявление массива
                for (int i = 0; i < bd; i++) {
                    cout << i + 1 << " element: ";
                    cin >> array[i];
                }
                cout << "array: " << "\n";
                Shell(array, bd);
                break;
            }
            default: {
                cout << "Error\n";
            }
        }
    }
}
