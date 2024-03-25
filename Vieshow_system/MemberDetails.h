// MemberDetails class definition
#ifndef __MEMBER_DETAILS_H__
#define __MEMBER_DETAILS_H__

#include "MemberDatabase.h" // MemberDatabase class definition

class MemberDetails
{
public:
	MemberDetails(MemberDatabase &theMemberDatabase);

	void execute(vector< Member >::iterator it);

private:
	MemberDatabase &memberDatabase; // reference to memberDatabase
}; // end class MemberDetails

#endif // MEMBER_DETAILS_H