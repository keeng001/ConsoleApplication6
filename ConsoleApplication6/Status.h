#pragma once
class Status
{
public:

	enum status {

		Hello,
		Ack,
		Respond, 
		NAck,
		Error,





	} s_status;


	Status();
	~Status();
};

