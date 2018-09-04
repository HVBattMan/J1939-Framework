/*
 * DM1.h
 *
 *  Created on: Oct 15, 2017
 *      Author: famez
 */

#ifndef DIAGNOSIS_FRAMES_DM1_H_
#define DIAGNOSIS_FRAMES_DM1_H_

#include <vector>

#include <GenericFrame.h>
#include <Diagnosis/DTC.h>

#define DM1_PGN			0x00FECA
#define DM1_NAME		"DM1"

namespace J1939 {

class DM1: public GenericFrame {
private:

	std::vector<DTC> mDtcs;

protected:
	void decodeData(const u8* buffer, size_t length);
	void encodeData(u8* buffer, size_t length) const;

public:
	DM1();
	virtual ~DM1();

	void addDTC(const DTC& dtc) { mDtcs.push_back(dtc); };

	size_t getDataLength() const override;
	std::string toString() override;

	IMPLEMENT_CLONEABLE(J1939Frame,DM1);
};

} /* namespace J1939 */

#endif /* DIAGNOSIS_FRAMES_DM1_H_ */
