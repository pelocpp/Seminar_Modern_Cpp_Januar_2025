// =====================================================================================
// LValue / RValue
// =====================================================================================

module modern_cpp:rvalue_lvalue;

namespace LValueRValue {

    // lvalue reference
    static void sayHello(std::string& message) {
        std::println("sayHello [std::string&]:  {}", message);
    }

    // rvalue reference
    static void sayHello(std::string&& message) {
        std::println("sayHello [std::string&&]: {}", message);
    }

    static void test01() {

        std::string a = "Hello";
        std::string b = " World";

        sayHello(a);

        std::string tmp = a + b;

        sayHello(a + b);  // konkatenieren : "Hello World"
    
    
    }

    // -------------------------------------------------------------------

    static void helper(std::string&& message) {

        sayHello(std::move(message));   // a) Das mit dem RValue
                             // b) Zuvor anonymes Objekt hat
                             //    jetzt einen Namen (Parameter)
    }

    static void test02() {

        //std::string a = "ABC";
        //helper(a);

        helper(std::string("ABC"));
    }

    // -------------------------------------------------------------------

    static void test03() {

        std::string s = "Hello";

        sayHello(s);
        // versus
        sayHello(std::move(s));  // casts an lvalue to an rvalue
    }

    // -------------------------------------------------------------------

    static void test04() {

        // int& i = 2;          // invalid: reference to a constant

        // int a = 2;
        // int b = 3;

        // int& k = a + b;     // invalid: reference to a temporary

        int&& i = 2;           // works: reference to a constant

        int a = 2;
        int b = 3;

        int&& k = a + b;       // works: reference to a temporary
    }
}

void main_rvalue_lvalue() 
{
    int n = 123;

    // C - stilistisch
    int* ip;
    ip = &n;

    // C++ - stilistisch
    // int& ri;    // NO-WAY: Leere Referenz // NULL-Referenz
    int& ri = n;   // ri:  Alias(name)

    using namespace LValueRValue;
    test01();
    test02();
    test03();
    test04();
}

// =====================================================================================
// End-of-File
// =====================================================================================
