class Solution {
    public double angleClock( int hour, int minutes ) {
        double ratioMinutes = (double) minutes / 60;
        double minutesAig = (double) minutes / 60 * 360;
        double hourAig = 360 * hour / 12  + 30 * ratioMinutes;
        
        if ( hourAig > 360 )
            hourAig -= 360;
        
        // System.out.println("minutesAig : " + minutesAig);
        // System.out.println("hourAig : " + hourAig);
        
        return Math.min( Math.abs(hourAig - minutesAig), 360 - Math.abs(hourAig - minutesAig) );
    }
}
