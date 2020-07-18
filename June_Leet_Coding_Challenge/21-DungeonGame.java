class Solution {
    public int calculateMinimumHP( int[][] dungeon ) {

        int row = dungeon.length;
        int column = dungeon[0].length;

        int[][] healthPoint = new int[row][];
        for (int i = 0; i < healthPoint.length; i++) {
            healthPoint[i] = new int[column];
        }

        if ( dungeon[row - 1][column - 1] >= 0 ) {
            healthPoint[row - 1][column - 1] = 1;
        } else {
            healthPoint[row - 1][column - 1] = 1 - dungeon[row - 1][column - 1];
        }

        for (int i = row - 2; i >= 0; i--) {
            healthPoint[i][column - 1] = compute(dungeon[i][column - 1],
                    healthPoint[i + 1][column - 1]);
        }

        for (int j = column - 2; j >= 0; j--) {
            healthPoint[row - 1][j] = compute(dungeon[row - 1][j], healthPoint[row - 1][j + 1]);
        }

        for (int i = row - 2; i >= 0; i--) {
            for (int j = column - 2; j >= 0; j--) {
                healthPoint[i][j] = Math.min( compute(dungeon[i][j], healthPoint[i + 1][j]),
                        compute(dungeon[i][j], healthPoint[i][j + 1]) );
            }
        }

        return healthPoint[0][0];
    }

    private int compute( int value, int preRes ) {
        if ( value == 0 )
            return preRes;

        if ( value > 0 ) {
            if ( value >= preRes )
                return 1;
            return preRes - value;
        }

        return preRes - value;
    }
}
