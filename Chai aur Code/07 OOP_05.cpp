class Student {
public:
    static int count;

    static void showCount() {
        cout << count;
    }
};

int Student::count = 0;


// this is how to static function and member 