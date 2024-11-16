#include <iostream>
#include <string>
#include <stdexcept>
#include "ListPS3.h"

using namespace std;

#ifdef P0

void testP0()
{
    cout << "Test basic setup:" << endl;

    List<string> lList;
    
    lList.remove( "P0" );
    lList.remove( string( "P0" ) );

    cout << "Complete" << endl;
}
int main()
{
    P0
    testP0();

    return 0;
}

#endif

#ifdef P1

void testP1()
{
    using StringList = List<string>;    
    
    string s1( "AAAA" );
    string s2( "BBBB" );
    string s3( "CCCC" );
    string s4( "DDDD" );

    cout << "Test of problem 1:" << endl;

    StringList lList;

    if ( !lList.empty() )
    {
        cerr << "Error: Newly created list is not empty." << endl;
    }
    
    lList.push_front( s4 );
    lList.push_front( s3 );
    lList.push_front( s2 );
    lList.push_front( s1 );
    
    cout << "Top to bottom " << lList.size() << " elements:" << endl;
    for ( const string& element : lList )
    {
      cout << element << endl;
    }

    cout << "Bottom to top " << lList.size() << " elements:" << endl;
    for ( StringList::Iterator iter = lList.rbegin(); iter != iter.rend(); iter-- )
    {
      cout << *iter << endl;
    }

    cout << "Completed" << endl;
}
int main()
{
    P1
    testP1();

    return 0;
}

#endif

#ifdef P2

void testP2()
{
    using StringList = List<string>;
    
    string s1( "AAAA" );
    string s2( "BBBB" );
    string s3( "CCCC" );
    string s4( "DDDD" );
    string s5( "EEEE" );
    string s6( "FFFF" );

    cout << "Test of problem 2:" << endl;

    StringList lList;
    
    lList.push_front( s4 );
    lList.push_front( s3 );
    lList.push_front( s2 );
    lList.push_front( s1 );
    lList.push_back( s5 );
    lList.push_back( s6 );
    cout << "Bottom to top " << lList.size() << " elements:" << endl;
    for ( StringList::Iterator iter = lList.rbegin(); iter != iter.rend(); iter-- )
    {
      cout << *iter << endl;
    }
    
    cout << "Completed" << endl;
}
int main()
{
    P2
    testP2();

       return 0;
}

#endif

#ifdef P3

void testP3()
{
    using StringList = List<string>;

    string s1( "AAAA" );
    string s2( "BBBB" );
    string s3( "CCCC" );
    string s4( "DDDD" );
    string s5( "EEEE" );
    string s6( "FFFF" );

    StringList lList;

    lList.push_front( s4 );
    lList.push_front( s3 );
    lList.push_front( s2 );
    lList.push_front( s1 );
    lList.push_back( s5 );
    lList.push_back( s6 );

    cout << "Test problem 3:" << endl;

    try
    {
        cout << "Element at index 4: " << lList[4] << endl;
        lList.remove( s5 );
        cout << "Element at index 4: " << lList[4] << endl;
        
        cout << "Element at index 6: ";
        cout << lList[6] << endl;
        cout << "Error: You should not see this text." << endl;
    }
    catch (out_of_range e)
    {
        cerr << "\nSuccessfully caught error: " << e.what() << endl;
    }
    
    cout << "Completed" << endl;
}
int main()
{
    P3
    testP3();

    return 0;
}
#endif

#ifdef P4

void testP4()
{
    using StringList = List<string>;

    string s1( "AAAA" );
    string s2( "BBBB" );
    string s3( "CCCC" );
    string s4( "DDDD" );
    string s5( "EEEE" );
    
    List<string> lList;
    
    cout << "Test of problem 4:" << endl;

    lList.push_front( s4 );
    lList.push_front( s3 );
    lList.push_front( s2 );
    
    List<string> copy( lList );
    
    cout << "A - Top to bottom " << copy.size() << " elements:" << endl;
    
    for ( const string& element : copy )
    {
        cout << element << endl;
    }
    
    lList = copy;
    
    lList.push_front( s1 );
    lList.push_back( s5 );
    
    cout << "B - Bottom to top " << lList.size() << " elements:" << endl;
    
    for ( auto iter = lList.rbegin(); iter != iter.rend(); iter-- )
    {
        cout << *iter << endl;
    }
    
    cout << "Completed" << endl;
}
int main()
{
    P4
    testP4();

    return 0;
}
#endif

#ifdef P5

void testP5()
{
    using StringList = List<string>;

    string s2( "CCCC" );
    
    List<string> lList;

    cout << "Test of problem 5:" << endl;

    lList.push_front( string( "DDDD" ) );
    lList.push_front( std::move(s2) );
    lList.push_front( "BBBB" );
    
    if ( s2.empty() )
    {
        cout << "Successfully performed move operation." << endl;
    }
    else
    {
        cerr << "Error: Move operation failed." << endl;
    }
    
    cout << "A - Top to bottom " << lList.size() << " elements:" << endl;

    for ( const string& element : lList )
    {
        cout << element << endl;
    }
    
    List<string> move( std::move(lList) );

    if ( lList.empty() )
    {
        cout << "Successfully performed move operation." << endl;
    }
    else
    {
        cerr << "Error: Move operation failed." << endl;
    }

    cout << "B - Top to bottom " << move.size() << " elements:" << endl;
    
    for ( const string& element : move )
    {
        cout << element << endl;
    }
    
    lList = std::move(move);
    
    if ( move.empty() )
    {
        cout << "Successfully performed move operation." << endl;
    }
    else
    {
        cerr << "Error: Move operation failed." << endl;
    }

    lList.push_front( "AAAA" );
    lList.push_back( "EEEE" );
    
    cout << "C - Bottom to top " << lList.size() << " elements:" << endl;
    
    for ( auto iter = lList.rbegin(); iter != iter.rend(); iter-- )
    {
        cout << *iter << endl;
    }
    
    cout << "Completed" << endl;
}
int main()
{
    P5
    testP5();

    return 0;
}
#endif

