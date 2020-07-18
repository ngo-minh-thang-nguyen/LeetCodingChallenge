class Solution {
public:
    string validIPAddress( string IP ) {
        string delimiterV4 = ".";
        string delimiterV6 = ":";
        bool isV4 = false;
        bool isV6 = false;
        if ( IP.find( delimiterV4 ) != string::npos ) {
            isV4 = true;
            IP += delimiterV4;
        }
        else if ( IP.find( delimiterV6 ) != string::npos ) {
            isV6 = true;
            IP += delimiterV6;
        }
        
        if ( isV4 ) {
            int i = 0;
            int nb = 0;
            while ( i < IP.size() ) {
                nb++;
                string token = IP.substr( i, IP.substr(i, IP.size() - i).find( delimiterV4 ) );
                
                if ( token == "" )
                    return "Neither";
                
                if ( token.size() > 5 )
                    return "Neither";
                
                if ( ! is_number( token ) )
                    return "Neither";
                
                int nbToken = stoi( token );
                if ( 0 > nbToken || nbToken > 255 ) 
                    return "Neither";
                        
                i += IP.substr(i, IP.size() - i).find( delimiterV4 ) + 1;
            }
                
            if ( nb > 4 || nb < 4 )
                return "Neither";
            
            return "IPv4";
        }
        else if ( isV6 ) {
            int i = 0;
            int nb = 0;
            while ( i < IP.size() ) {
                nb++;
                string token = IP.substr( i, IP.substr(i, IP.size() - i).find( delimiterV6 ) );
                
                if ( token == "" )
                    return "Neither";
                
                if ( ! is_Hexa( token ) )
                    return "Neither";
                        
                i += IP.substr(i, IP.size() - i).find( delimiterV6 ) + 1;
            }
                
            if ( nb > 8 || nb < 8 )
                return "Neither";
            
            return "IPv6";
        }
        else
            return "Neither";
    }
    
    bool is_number( const string& s ) {
        if ( s[0] == '0' && s.size() > 1 )
            return false;
        else {
            for ( int i = 0; i < s.size(); i++ ) {
                if ( ! isdigit( s[i] ) ){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool is_Hexa( const string& token ) {
        vector<char> hexaVect = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                 'a', 'b', 'c', 'd', 'e', 'f'};
        int nbChar = 0;
        
        for ( char aChar : token ) {
            nbChar++;
            if ( nbChar > 4 )
                return false;
            
            if ( find( hexaVect.begin(), hexaVect.end(), aChar ) == hexaVect.end() )
                return false;
        }
        
        return true;
    }
};
