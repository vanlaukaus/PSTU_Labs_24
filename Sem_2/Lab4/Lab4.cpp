#include <iostream>
#include <cstdlib>
using namespace std;
int main () {
    int elements_in_array = 100, size_arr, del_element;
    int arr[elements_in_array]; //формируем массивы
    cout << "Enter a count of numbers (min 1 max 50): ";
    cin >> size_arr;
    srand(time(0));
    if (size_arr < elements_in_array && size_arr > 0) {

        for (int i = 0; i < size_arr; i++) { //заполняем массив рандомными значениями 
            arr[i] = rand()%100 - 50; //от -50 до 49 значения
        }
        
        cout << "Array original: ";
        for (int i = 0; i < size_arr; i++) { //выводим массив
           cout << arr[i] << " "; 
        }
        cout << endl;
        
        cout << "Enter an element to delete: "; //вводим K для удаления
        cin >> del_element;
        
        for (int i = 0; i < size_arr; i++) { //удаляем
            if (arr[i] == del_element) {
                 for (int j = i; j < size_arr - 1; j++) {
                    arr[j] = arr[j+1]; //сдвигаем влево
                 }
                 size_arr--;
                 i--;
            }  
        }

       for (int i = 0; i < size_arr; i++) { //для вставки элемента 0 после четного
            if (arr[i] % 2 == 0) {
                for (int j = size_arr-1; j > i; j--){
                    arr[j+1] = arr[j]; //сдвиг вправо
                }
                arr[i+1] = 0;
                size_arr++;
                i++;
            }
        } 
        
        cout << "Array now: ";
        for (int i = 0; i < size_arr; i++) { //вывод
            cout << arr[i] << " ";
        }
        cout << endl;

    }
    else {
        cout << "You need in another number" << endl;
    }

    return 0;
}