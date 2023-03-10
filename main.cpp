#include <iostream>
#include <string>
#include "SearchServer.h"


#include "InvertedIndex.h"
#include "ConverterJSON.h"

#include <thread>
int main() {
    ConverterJSON converter;

    InvertedIndex inverted_index;
    inverted_index.UpdateDocumentBase(converter.GetTextDocuments());
    std::vector<std::string> requests=converter.GetRequests();
    std::string req1=requests[1];

    for(int j=0;j<requests.size();j++){
        inverted_index.GetWordCount(requests[j]);
    }





    std::map<std::string, std::vector<Entry>> freq_dictionary;
    freq_dictionary=inverted_index.GetFreq_dictionary();


    SearchServer search_server;
    search_server.setFreqDictionari(inverted_index.GetFreq_dictionary());


    converter.putAnswers(search_server.Search(converter.GetRequests(),converter.GetTextDocuments()));

}
