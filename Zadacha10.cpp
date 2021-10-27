// Zadacha10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "This proram build nagic square N * N\n";
    long long int* a;
    long long int* b;
    long long int k;
    int n;
    std::cout << "Enter N\n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong N!\n";
        std::cout << "Enter N another time\n";
        std::cin >> n;
    }
    a = (long long int*)malloc(n * n * sizeof(long long int));

    std::cout << "\n";
    std::cout << "Magic square is: \n";
    std::cout << "\n";
    if (n % 2 == 1)
    {
        k = (n + 1) / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(a + i * n + j) = long long int((i + j + k) % n + 1);
            }
        }

        b = (long long int*)malloc(n * n * sizeof(long long int));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(b + i * n + j) = long long int(((n + (i - j) + (k - 1)) % n) * n);
                *(a + i * n + j) += *(b + i * n + j);
            }
        }

        /* for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout<<"|\t"
                // std::cout << *(a + i * n + j) << " ";
                std::cout << "\t" << *(b + i * n + j);
            }
            std::cout << "\n";
        } */
    }
    else if (n % 4 == 2)
    {
        int c = n - 2;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                k = (i - 1) * c + j;
                // *(a + i * n + j) = k;
                if ((i % 4 == j % 4) || ((i + j) % 4 == 1))
                {
                    *(a + i * n + j) = c * c + 1 - k;
                }
                else
                {
                    *(a + i * n + j) = k;
                }

                if (*(a + i * n + j) > (c * c) / 2)
                {
                    *(a + i * n + j) += long long int(n * n - c * c);
                }
            }
        }

        *(a + 0 * n + 0) = long long int(c * c / 2 + 1);
        *(a + 0 * n + (n - 1)) = long long int (n * n / 2 - 2);
        *(a + (n - 1) * n + 0) = long long int(n * n /2 + 3);
        *(a + (n - 1) * n + (n - 1)) = long long int(n * n - c * c / 2);

        k = (n * n - c * c / 2) - 2;
        for (int i = 1; i < n - 1, k > n * n / 2 + 9; i++)
        {
            *(a + i * n + 0) = k;
            *(a + i * n + (n - 1)) = n * n + 1 - k;
            if (k % 8 == 2)
            {
                k -= 1;
            }
            else if (k % 8 == 1)
            {
                k -= 7;
            }
        }

        k = (n * n - c * c / 2) - 6;
        for (int i = n - 2; i > 0 && k > n * n / 2 + 9; i--)
        {
            *(a + i * n + (n - 1)) = k;
            *(a + i * n + 0) = long long int(n * n + 1 - k);
            if (k % 8 == 6)
            {
                k -= 1;
            }
            else if (k % 8 == 5)
            {
                k -= 7;
            }
        }

        k = (n * n - c * c / 2) - 1;
        for (int j = 1; j < n - 1 && k > n * n / 2 + 9; j++)
        {
            *(a + 0 * n + j) = k;
            *(a + (n - 1) * n + j) = n * n + 1 - k;
            if (k % 8 == 3)
            {
                k -= 3;
            }
            else if (k % 8 == 0)
            {
                k -= 5;
            }
        }

        k = (n * n - c * c / 2) - 5;
        for (int j = n - 2; j > 0 && k > n * n / 2 + 9; j--)
        {
            *(a + (n - 1) * n + j) = k;
            *(a + 0 * n + j) = n * n + 1 - k;
            if (k % 8 == 7)
            {
                k -= 3;
            }
            else if (k % 8 == 4)
            {
                k -= 5;
            }
        }

        *(a + 0 * n + (n / 2 - 2)) = long long int(n * n / 2 + 9);
        *(a + (n - 1) * n + (n / 2 - 2)) = n * n + 1 - *(a + 0 * n + (n / 2 - 2));
        *(a + 0 * n + (n / 2 - 1)) = long long int(n * n / 2 + 7);
        *(a + (n - 1) * n + (n / 2 - 1)) = n * n + 1 - *(a + 0 * n + (n / 2 - 1));
        *(a + 0 * n + (n / 2)) = long long int(n * n / 2 + 5);
        *(a + (n - 1) * n + (n / 2)) = n * n + 1 - *(a + 0 * n + (n / 2));

        *(a + (n / 2 - 2) * n + 0) = long long int(n * n / 2 + 6);
        *(a + (n / 2 - 2) * n + (n - 1)) = n * n + 1 - *(a + (n / 2 - 2) * n + 0);
        *(a + (n / 2 - 1) * n + 0) = long long int(n * n / 2 + 4);
        *(a + (n / 2) * n + 0) = long long int(n * n / 2);
        *(a + (n / 2 + 1) * n + 0) = long long int(n * n / 2 - 1);
        *(a + (n / 2 + 1) * n + (n - 1)) = n * n + 1 - *(a + (n / 2 + 1) * n + 0);

        *(a + (n - 1) * n + (n / 2 + 1)) = long long int(n * n / 2 + 8);
        *(a + 0 * n + (n / 2 + 1)) = n * n + 1 - *(a + (n - 1) * n + (n / 2 + 1));

        *(a + (n / 2 - 1) * n + (n - 1)) = long long int(n * n / 2 - 3);
        *(a + (n / 2) * n + (n - 1)) = long long int(n * n / 2 + 1);


    }
    else if (n % 4 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                k = i * n + j; 
                if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                {
                    *(a + i * n + j) = n * n - k;
                }
                else
                {
                    *(a + i * n + j) = k + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout<<"|\t"
            // std::cout << *(a + i * n + j) << " ";
            std::cout << *(a + i * n + j) << "\t";
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
