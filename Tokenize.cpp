#include "Tokenize.h"

void Tokenize::tokenize(std::string line)
{
	unsigned int row = rows.size();
	unsigned int column = 0;
	unsigned int pos = 0;
	Row r;
	while (!line.empty()) {
		pos = line.find('\t');
		++column;

		if (pos == 0 && row == 0)
		{
			std::string s;
			s += "ERROR: There is an error in the  ";
			s += std::to_string(row + 1);
			s += " row ";
			s += std::to_string(column);
			s += " column\n";
			throw FormatException(s);
		}
		else if (pos == 0)
		{
			std::string s;
			s += "WARNING: There is no argument in  ";
			s += std::to_string(row + 1);
			s += " row ";
			s += std::to_string(column);
			s += " column\n";
			r.addWarning(Warning(s));
		}

		std::string s = line.substr(0, pos);
		r.addRowValue(s);
		unsigned int n = std::string::npos;
		if (pos != n && !line.empty())
		{
			s = line.substr(pos, 1);
		}
		if (pos != n)
		{
			line.erase(pos, 1);
		}
		line.erase(0, pos);

		if (line.empty() && s == "\t")
		{
			std::string s;
			s += "WARNING: There is not argument in  ";
			s += std::to_string(row + 1);
			s += " row ";
			s += std::to_string(column + 1);
			s += " column\n";
			r.addWarning(Warning(s));
		}
	}

	rows.push_back(r);
	if (!rows[0].getRowValues().empty() && row != 0 && rows[0].getRowValues().size() < r.getRowValues().size())
	{
		std::string s;
		s += "WARNING: The number of arguments is higher than expected in ";
		s += std::to_string(row + 1);
		s += " row\n";
		Row rr;
		rr.addWarning(Warning(s));
		for (unsigned int i = 0; i < rows[0].getRowValues().size(); ++i)
		{
			rr.addRowValue("\t");
		}
		rows.pop_back();
		rows.push_back(rr);
	}
}

const std::vector<Row>& Tokenize::getRows()
{
	return rows;
}