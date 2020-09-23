using namespace std;

string decodeMorse(string morseCode) {
    
    string divided_blank = "";
    string decoded = "";
  
    for(auto token : morseCode){  
        if(token == ' ')
        {          
          if(divided_blank != "")
          {
            decoded += MORSE_CODE[divided_blank];
            divided_blank = "";
          }
          else if(!decoded.empty())
          {
            divided_blank = " ";
            decoded += divided_blank;
          }
        }
        else
        {
          divided_blank += token;
        }
    }
  
    decoded += MORSE_CODE[divided_blank];
  
    while(decoded.back() == ' '){
      decoded.pop_back();
    }
  
    return decoded;
}