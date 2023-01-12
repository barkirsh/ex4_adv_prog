# include "Command.h"
# include ""
class ClassifyDataCommand : public Command{
    /**
     * constructor of Classifying data
     * @param path_classified
     * @param path_test
     * @param k
     * @param distance
     */
    ClassifyDataCommand(string path_classified, string path_test, int k, string distance);
};