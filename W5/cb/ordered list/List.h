enum Error_code{underflow, overflow, range_error_new, success, fail, not_present};
const static int max_list = 30;

using namespace std;

template <class List_entry>
class List
{
public:
    // methods of theList ADT
    List( );
    int size( ) const;
    bool full( ) const;
    bool empty( ) const;
    void clear( );
    void traverse(const List_entry &x,Error_code (*visit)(int,List_entry &));
    Error_code retrieve(int position, List_entry &x) const;
    //virtual Error_code replace(int position, const List_entry &x);
    Error_code replace(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
   // virtual Error_code insert(int position, const List_entry &x);
    Error_code insert(int position, const List_entry &x);
protected:
    // data members for a contiguous list implementation
    int count;
    List_entry entry[max_list];
};

