// This one is heavy on the error handeling. But i haven't been using it, and I
// should. I also tried to find different ways of debugging, or handeling errors.
// I made sure to include some try/catch.

#include <iostream>
#include <stdexcept>


using namespace std;



template <typename Type>
class acts_like_Vector {

	private:
		Type* info;
		int size;
	
	public:
	
		// Constructor(s)
		acts_like_Vector () : info(NULL), size(0){}
		
		// Destructor
		~acts_like_Vector(){
			
			delete[] info;
			
		}
		
		// CLASS FUNCTIONS
		
		// add an element to the end of the array - .addElement( param). Use try/catch 
		// to make sure memory for the new array is allocated correctly. 
		
		void add_Element(Type input){
			
			try{
				
				if(info == 0 ){
					
					info = new Type[1];
					info[0] = input;
					size = 1;
					
				}else{
				
					Type *new_Info = new Type[size + 1];
					
					for(int i = 0; i < size; i++){
						
						new_Info[i] = info[i];
						
					}
					
					new_Info[size] = input;
					delete[] info;
					info = new_Info;
					size++;
					
				}
				
				cout << "Add element was successful.\n" << endl;
				
			}
			
			
			// Catches memory allocation error
			catch(const bad_alloc& e){
				
				cerr << "\nNew Memory ALlocation Unsuccessful!!\n" << e.what() << endl;	
			}
			
			// Catches other generic exceptions 
			catch(...){
				
				cerr << "\nAn unexpected error has occured.\n" << endl;
			}
			
			
		}
		
		
			
		// I got curious and looked at different ways to be able to add 
		// multiple elements at a time. I saw using a std vector, but wanted to 
		// try something new.
		
		void add_ElementS(initializer_list<Type> inputs){
			
			try{
				
				int new_Elements = inputs.size();
				Type* new_Info = new Type[size + new_Elements];
				
				 // copies any existing elements
				for (int i = 0; i < size; i++){
					
					new_Info[i] = info[i];
				}
				
				int index = size;
				for (const Type& input : inputs){
					
					new_Info[index++] = input;
				}
				
				delete[] info;
				info = new_Info;
				size += new_Elements;
				
				cout << "\nAddition of multiple elements succeded!\n" << endl;
		
			} catch (const bad_alloc& e){
				
				cerr << "\nNew Memory Allocation Failed!" << e.what() << endl;
					
			} catch (...){
				
				cerr << "\nAn unexpected error has occured." << endl;
			}
			
		}
		
		
		
		//implement a function called .at(int param) that returns the value in the array at the location param.
		Type at(int position){
			
			if (position < 0 || position >= size){
				
				throw out_of_range("Index out of bounds. NO SOUP FOR YOU!!!");
			
			} 
			
			cout << "THe element at position " << position << " is " 
				 << info[position] << ".\n" << endl;
				 
			return info[position];
		
		}
		
		
		//.size() function that returns the size of the array.
		int get_Size() const {
			
			return size;
		}
		
		//implement a .sum() function that returns the sum of the entire array.
		Type sum_Array(){
			
			Type sum = 0;
			int i = 0;
			
			try{
				
				while (i < get_Size()){
					
					if (info == NULL){
						
						throw runtime_error ("Array pointer is NULL! You can't add nothing to nothing!");
					}
					
					sum += info[i];
					i++;
				}
				
			}catch (const exception& e){
				
				cerr << "ERROR: " << e.what() << endl;
				return 0;
			}
			
			return sum;
		}
		
		
		//implement a .max() and .min() function that finds the maximum and minimum of the entire array.
		Type array_Max() const{
			
			if (size == 0){
				
				throw runtime_error("An empty array has no max.");
			}
			
			Type max_Value = info[0];
			for (int i = 0; i < size; i++){
				
				if(info[i] > max_Value){
					
					max_Value = info[i];
				}
			}
			
			
			cout << "The maximum Value of your array is " << max_Value << ".\n" << endl;
			
			return max_Value;

		}
		
		Type array_Min() const{
			
			if (size == 0){
				
				throw runtime_error("An empty array has no max.");
			}
			
			Type min_Value = info[0];
			for (int i = 0; i < size; i++){
				
				if(info[i] < min_Value){
					
					min_Value = info[i];
				}
			}
			
			
			cout << "The minimum Value of your array is " << min_Value << ".\n" << endl;
			
			return min_Value;

		}
		
		//Create a .slice(int begin, int end) function that returns a slice of the array between and including elements begin to end. 
		Type* slice(int begin, int end)const{
			
			
				
			if (begin < 0 || end > size || begin > end) {
				
				throw out_of_range("Not a good beginning or end. Slice not valid.");
			}
			
			int new_Size = end - begin + 1;
			
			Type* array_Slice = new Type[new_Size];
			
			cout << "Your array slice is \n[";
			
			for (int i = begin - 1; i < new_Size + 2; i++){
				
				array_Slice[i] = info[i];
				
				cout << array_Slice[i] << " ,";
			}
			
			cout << "]\n" << endl;
			return array_Slice;
			
				
		}
		
		// Print all of the elements of the array
		void print()const{
			
			int i = 0;
			
			cout << "The elements of your array are: \n[";
			
			for (int i = 0; i < size; i++){
				
				cout << info[i - 1] << ", ";
			} 
			
			cout << info[1] << "] \n" << endl;
		}
	
	
};



/***************************************************************************************************/

int main(){
	
	cout << "\n\n" << endl;
	
//////////////////////////// Add Sing Elements //////////////////////////


	cout << "////////////////////// Add Single Elements //////////////////////////\n" << endl;
	acts_like_Vector <double> double_Array;
	
	double_Array.add_Element(52.3);
	double_Array.add_Element(400);
	double_Array.add_Element(.2587);
	double_Array.add_Element(5);
	double_Array.add_Element(69);
	double_Array.add_Element(1021);
	double_Array.add_Element(.854123);
	double_Array.add_Element(.0000000447);
	double_Array.add_Element(1258);
	double_Array.add_Element(45);
	double_Array.add_Element(3);
	double_Array.add_Element(10);
	
	double_Array.print();
	
	cout << "\nArray size: " << double_Array.get_Size() << ".\n" << endl;
    cout << "Array sum: " << double_Array.sum_Array() << ".\n" << endl;
	
	double_Array.at(6);
	double_Array.at(0);
	// double_Array.at(13);    // Testing for out of bounds exception
	
	double_Array.array_Max();
	double_Array.array_Min();
	
	
	
//////////////////////////// Add Multiple Elements //////////////////////////	

	cout << "\n\n////////////////////// Add Multiple Elements //////////////////////////" << endl;
	double_Array.add_ElementS({10, 20, 30, 40, 50, 60, 70, 80, 90, 5268,});
	double_Array.print();
	
	cout << "\nArray size: " << double_Array.get_Size() << ".\n" << endl;
    cout << "Array sum: " << double_Array.sum_Array() << ".\n" << endl;
	
	double_Array.at(6);
	double_Array.at(0);
	// double_Array.at(13);    // Testing for out of bounds exception
	
	double_Array.array_Max();
	double_Array.array_Min();
	
	
////////////////////////////// Slice Array ///////////////////////////////////

	// double_Array.slice(2, 28);  // testing for out of bounds exception
	double_Array.slice(3, 8);
	double_Array.slice(9, 18);
	
	
	return 0;
}


// I couldn't quite get my slice to work with the adding of multiple elements. 
// THere is also something not quite right of the adding of multiple elements
// to an exsiting array.