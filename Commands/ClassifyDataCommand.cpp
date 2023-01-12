# include "ClassifyDataCommand.h"

void Command:: execute(){
    bool isUploaded = true; // for checikng if files were uploaded
    // check if files csv were uploaded: , ask server if files were uploaded
    if (isUploaded){
        // applying algorithm on uploaded files -> in the end the test file will be classified with result

        Knn algExecuter;
        dio.write("classifying data complete");
    }
    // if files werent uploaded
    dio.write("please upload data");

}

ClassifyDataCommand:: ClassifyDataCommand(string path_classified, string path_test, int k, string distance){
    this.describtion = "classify data";

}
