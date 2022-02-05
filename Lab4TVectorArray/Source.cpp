#include "TVectorArray.h"

int _count_elem;
int print_menu(int key)
{
    string menu[]{ "Что вы хотите сделать ? ", "1.Ввести массив в шаблонном классе выбрав тип",
                   "2.Модифицировать элемент", "3.Отсортировать массив и вывести" ,
                   "4.Вывести число элементов больше среднего", "5.Закончить работу с программой" };
    int _count_elem = sizeof(menu) / sizeof(string);
    if (key != 1)
        for (int i = 0; i < _count_elem; i++)
        {
            cout << menu[i] << endl;
        }
    return _count_elem - 1;
}

int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);
    if (s == "") getline(cin, s);
    while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant <1 || variant>count)
    {
        cout << "Ввод некорректен. Попробуйте снова: ";
        getline(cin, s);
    }
    return variant;
}

int main()
{
    constexpr int _size = 4;
    TVectorArray<_size, T3DVector> SomeV1;

    setlocale(LC_ALL, "");
    int count_elem = print_menu(1), variant = 0;
    string user_choise;
    do
    {
        print_menu(0);
        variant = get_variant(count_elem);
        switch (variant)
        {
        case 1:
        {
            cout << "Manual или File: " << endl;
            getline(cin, user_choise);
            if (user_choise == "Manual")
                &SomeV1.scan(cin);
            else if (user_choise == "File")
            {
                string in_file_name;
                cout << "\nВведите название файла для ввода (Пример: F:\\temp\\hello.txt): \n ";
                cin >> in_file_name;
                ifstream F;
                F.open(in_file_name);
                if (F)
                    &SomeV1.scan(F);
            }
        }
            break;
        case 2:
        {
            err_out_of_range:
            try 
            {
                cout << "\nВведите номер элемента, который хотите модифицировать: " << endl;
                int temp;
                cin >> temp;
                cout << "\n Manual или SetRandomValue: " << endl;
                getline(cin, user_choise);
                if (user_choise == "") getline(cin, user_choise);
                if (user_choise == "Manual")
                {
                block2:
                    try
                    {
                        string s_t;
                        double t;
                        getline(cin, s_t);
                        stringstream ss(s_t);
                        if (!(ss >> t))
                            throw StringException();
                        if (t < 0 && temp == _size)
                            throw BellowZero();
                        SomeV1.SomeVec.at(temp) = t;
                    }
                    catch (StringException e)
                    {
                        cout << "Вы допустили ошибку при вводе, повторите ввод: " << endl;
                        ofstream err_out;
                        err_out.open(debug, ios::app);
                        err_out << "[" << __DATE__ << " " << __TIME__ << "] " << e.what() << endl;
                        err_out.close();
                        goto block2;
                    }
                    catch (BellowZero e)
                    {
                        cout << "Повторите ввод: " << endl;
                        ofstream err_out;
                        err_out.open(debug, ios::app);
                        err_out << "[" << __DATE__ << " " << __TIME__ << "] " << e.what() << endl;
                        err_out.close();
                        goto block2;
                    }
                }
                else if (user_choise == "SetRandomValue")
                {
                    SomeV1.SetRandomValue(temp);
                }
            }
            catch (const out_of_range)
            {
                cout << "Вы ввели неверное значение ячейки вектора, повторите ввод: " << endl;
                ofstream err_out;
                err_out.open(debug, ios::app);
                err_out << "[" << __DATE__ << " " << __TIME__ << "] Error: Invalid input (variable is not in vector's range)" << endl;
                err_out.close();
                goto err_out_of_range;
            }
            }
            break;
        case 3:
        {
            SomeV1.print(cout);
            SomeV1._sort();
            SomeV1.print(cout);
            string out_file_name;
            cout << "\nВведите название файла для ввода (Пример: F:\\temp\\out.txt): \n ";
            cin >> out_file_name;
            ofstream F;
            F.open(out_file_name);
            if (F)
                &SomeV1.print(F);
        }
            break;
        case 4:
        {
            cout << SomeV1._count_average();
        }
        break;
        default:
            break;
        }
    } while (variant != count_elem);
    return 0;
}