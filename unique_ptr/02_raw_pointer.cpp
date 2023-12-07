

int main() {

    {
        int* ptr = new int{10};
        
        // ...

        delete ptr;
    }

    {
        int value = 10;
        int* ptr = new int{10};

        // ...
        
        ptr = &value;
    }

    {
        int* ptr = new int[10];

        // ...

        delete[] ptr;
    }

    {
        int* ptr = new int[10];

        // if (...) {
            
        // } else if (...) {
        //     ...
        // } else if (...) {
        // 
        //     return ... !!!!!!!
        // } ...

        delete[] ptr;
    }

    return 0;
}
