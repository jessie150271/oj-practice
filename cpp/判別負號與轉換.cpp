void Math::setInput(string line) {
	istringstream ss(line);
	string in, temp;
	while (ss >> in)//消除空格
		temp += in;
	for (int i = 0; i < temp.size(); i++) {//將負號轉成'!'
		if ((!i && temp[i] == '-') || (temp[i] < '0' && temp[i] != ')' && i + 1 < temp.size() && temp[i + 1] == '-')) {
			if (i)
				input += temp[i++];
			input += '!';
		}
		else
			input += temp[i];
	}
}