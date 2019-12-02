#include "Vector.h"

namespace Vector
{
//Default constructor.

            vector::vector()
            {
                sz = 0;
                space = 0;
                arr = nullptr;
            }

            vector::vector(int n)
            {
                sz = n;
                space = n;
                arr = new int[n];
                for (int i = 0; i < n; i++){
                    arr[i] = 0;
                }
            }

            int vector::get(int i) const
            {
                return arr[i];
            }

            void vector::set(int i, int x)
            {
                arr[i] = x;
            }

            int vector::size()
            {
                return sz;
            }

            int vector::capacity()
            {
                return space;
            }

            void vector::push_back(int x)
            {
                if (sz == 0){
                    reserve(1);
                }
                else if (sz == space){
                    reserve(2 * space);
                }
                arr[sz] = x;
                sz++;
            }

            void vector::reserve(int n)
            {
                int *temp = new int[n];
                for(int i = 0; i < sz; i++){
                    *(temp + i) = *(arr + i);
                }
                delete[] arr;
                arr = temp;
                space = n;

            }


}
