# include "DisplayResultCommad.h"
// displaying for each raw of test file it classification
void Command :: execute(){
    bool isUploaded = true; // for checikng if files were uploaded , ask server if file were uploaded
    bool isClassified = true; // ask server if files are classified
    // check if files csv were uploaded:
    if (isUploaded && isClassified){
        // need to go through the file cad print "rowNo      classification"
        cout<< "Done."<<endl;
    }
    else if (!isUploaded) {  // if files werent uploaded
        dio.write("please upload data");
    }
   else (!isClassified){ // files werent classified
       dio.write("data the classify please.");
   }

}