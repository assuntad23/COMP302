/*
 * IOFile.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Assunta
 */

#ifndef IOFILE_H_
#define IOFILE_H_
#include <map>
#include <string>

class IOFile {
public:
	IOFile();
	virtual ~IOFile();
	std::ifstream OpeningForReading();
	void OpeningAndWriting(std::map<std::string, int> WordCounts);
};

#endif /* IOFILE_H_ */
