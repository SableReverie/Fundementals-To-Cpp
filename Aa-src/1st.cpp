#include <iostream>

int main(){

    // Type Conversion = conversion a value of one data type to another data type
    // implicit conversion (automatic type conversion) = conversion of a smaller data type to a larger data type
    // explicit conversion (manual type conversion) = conversion of a larger data type to a smaller

    #include <iostream>

    // ==========================================
    // 1. IMPLICIT CONVERSION (Automatic)
    // ==========================================
    int num_int = 25;
    
    // The compiler automatically converts the integer 25 into a double (25.0)
    // because a double variable is expecting a floating-point value.
    double num_double = num_int; 
    
    std::cout << "Implicit Conversion (int to double): " << num_double << "\n";


    // ==========================================
    // 2. EXPLICIT CONVERSION (Manual Type Casting)
    // ==========================================
    double pi = 3.14159;
    
    // We use 'static_cast<int>' to manually force the compiler to convert 
    // the double to an integer. This intentionally truncates the decimals (.14159).
    int truncated_pi = static_cast<int>(pi); 
    
    std::cout << "Explicit Conversion (double to int): " << truncated_pi << "\n";
    
    return 0;
}