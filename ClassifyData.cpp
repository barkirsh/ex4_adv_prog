# include "ClassifyData.h"

void Command:: execute(){
    bool isUploaded = true; // for checikng if files were uploaded
    // check if files csv were uploaded:
    if (isUploaded){
        // applying algorithm on uploaded files
        cout<< "classifying data complete"<<endl;
    }
    // if files werent uploaded
    cout << "please upload data"<<endl;

}