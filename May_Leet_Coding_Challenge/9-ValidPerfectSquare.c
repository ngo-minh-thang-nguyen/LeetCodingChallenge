
bool isPerfectSquare(int num){
    int n = 0;

    while ( n <= 46340 && n * n <= num ) {
        if ( n * n == num ) return true;
        
        n = n+1;
    }

    return false;
}



