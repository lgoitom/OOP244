#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds
{
	class Status {
		char* m_description = nullptr;
		int m_code = 0;
	public:
		Status(const char* description = nullptr);
		Status& operator=(int code);
		Status& operator=(const char* descrption);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		std::ostream& print(std::ostream& ostr) const;
	};
	std::ostream& operator<< (std::ostream& ostr, const Status& status);

}
#endif // SDDS_STATUS_H!