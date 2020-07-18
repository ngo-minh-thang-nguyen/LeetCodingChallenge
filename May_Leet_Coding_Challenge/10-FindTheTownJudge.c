

int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    if ( trustSize == 0 ) return 1;
    else {
        int arrayVote[1001] = { 0 };
        int judge = -1;
        
        for ( int i = 0; i < trustSize; i++ )
            arrayVote[ *(*(trust+i)+1) ]++;
            // if ( *(*(nums+1)+j) ) printf("i: %d; j: %d; trust: %d\n", i, j, trust[i][j]);

        for ( int i = 1; i <= N; i++ )
            if ( arrayVote[i] == N-1 ){
                bool findJudge = true;
                for ( int j = 0; j < trustSize; j++ ){
                    if ( i == *(*(trust+j)) ) {
                        findJudge = false;
                        break;
                    }
                }
                if ( findJudge ) judge = i;
            }

        return judge;
    }
}
