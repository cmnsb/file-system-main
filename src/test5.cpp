#include <iostream>
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"

using namespace std;

int main(){
    AbstractFile* imgFile = new ImageFile("image.img");
    AbstractFile* secretFile2 = new PasswordProxy(imgFile, "123");
    secretFile2 -> write({ 'X',' ','X',' ','X',' ','X',' ','X','3' });
    vector<char> result = secretFile2 -> read();

    AbstractFile* rawFile = new TextFile("secret.txt");
    AbstractFile* secretFile = new PasswordProxy(rawFile, "123");
    secretFile -> write({'H', 'e', 'l', 'l', 'o'});
    secretFile -> append({'!'});
    vector<char> expected = secretFile -> read();
    
    BasicDisplayVisitor bdv;
    MetadataDisplayVisitor mdv;
    secretFile -> accept(&bdv);
    secretFile->accept(&mdv);

    secretFile2 -> accept(&bdv);
    secretFile2->accept(&mdv);
    return 0;
}