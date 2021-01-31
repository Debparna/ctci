
 class pointer
 {
 public:
 void read();
 void reverse(char *str);
 
 };
 
 void pointer::reverse(char *buf)
 {
 char *reverseTemp = buf;
 
 while(*reverseTemp != '\0'){
 *reverseTemp++;
 }
 *reverseTemp--;
 
 char temp;
 while(buf < reverseTemp){
 temp = *buf;
 *buf = *reverseTemp;
 buf++;
 *reverseTemp = temp;
 reverseTemp--;
 }
 cout << reverseTemp << " ";
 }
 
 void pointer::read()
 {
 ifstream inf("/Users/Debparna/Desktop/deb/deb.txt");
 char buf[100];
 
 // while(!inf.eof()){
 //while (inf.getline(buf, 100)){
 while(inf){
 //char *str = new char[strlen(buf)+1];
 //strcpy(str, buf);
 inf.getline(buf, 100);
 
 char *token = strtok(buf, " ");
 while( token != NULL){
 reverse(token);
 //cout << token;
 token = strtok (NULL, " ");
 }
 }//end of inf.getline
 }// end of read
 
 int main(){
 pointer obj;
 
 //obj.read();
 char *buf = "my name is deb I neeeeeed";
 obj.reverse(buf);
 
 return 1;
 }
 
