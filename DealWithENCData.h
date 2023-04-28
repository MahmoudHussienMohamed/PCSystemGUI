#pragma once
namespace PCSystemGUI {
    #include <algorithm>
    class DealWithENCData {
    private:
        static int convert_to_int(string s) {
            int id = 0;
            for (auto& x : s) {
                id *= 10;
                id += (x - '0');
            }
            return id;
        }
        static string decription(string data, int id = 987654328) {
            id += 32;
            string decrepted_data;
            char dec_char{};
            for (auto x : data) {
                dec_char = (x - id) % 95;
                if (dec_char < 0)
                    dec_char += 95;
                decrepted_data += char(dec_char + 32);
            }
            return decrepted_data;
        }
    public:
        static pair<vector<string>, int> file_include_id(string file_name,string id) {
            ifstream edit_file(file_name);
            if(!edit_file)
                MessageBox::Show("Error occured while openning the file!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
            vector<string> data;
            string buffer;
            int line_number = -1;
            for (int i = 0; getline(edit_file, buffer); i++) {
                if (line_number == -1 && id == decription(buffer.substr(0, 6))) {
                    line_number = i;
                    string tmp = decription(buffer.substr(0, 6));
                    int id = convert_to_int(tmp);
                    tmp += decription(buffer.substr(6), id);
                    data.push_back(tmp);
                }else
                    data.push_back(buffer);
            }
            return {data, line_number};
        }
        static bool file_is_empty(ofstream& f) {
            f.seekp(0, f.end);
            bool empty = (f.tellp() == 0);
            f.seekp(0, f.beg);
            return empty;
        }
        static bool accepted_access(string day, string &today,string creator_name, string &username) {
            return today == day && username == creator_name;
        }
        static pair<vector<pair<int, int>>, vector<int>> reveiew_file(bool &error_occured, string username, string file_name, string &day, string id_from, string id_to) {
            error_occured = false;
            vector < pair<int, int>> duplicated;
            vector<int>missing;
            int id, to = convert_to_int(id_to), from = convert_to_int(id_from);
            int* data = new int[to - from + 1] {0};
            ifstream reveiewed_file(file_name);
            if (!reveiewed_file){
                MessageBox::Show("Cannot open the file! make sure that you entered the correct file", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
                error_occured = true;
            } else {
                string buffer;
                size_t username_from, username_to;
                while(getline(reveiewed_file, buffer)){
                    id = convert_to_int(decription(buffer.substr(0, 6)));
                    buffer = decription(buffer.substr(0, 6)) + decription(buffer.substr(6), id);
                    username_from = buffer.find(',', 25);
                    username_to = buffer.find(',', username_from + 1);
                    if (username != "Admin" && !accepted_access(buffer.substr(7, 10), day,
                        buffer.substr(username_from + 1, username_to - username_from - 1), username)) {
                        MessageBox::Show("You don't have access on this file!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        error_occured = true;
                        break;
                    }
                    if (id >= from && id <= to)
                        data[id - from]++;

                }
            }
            reveiewed_file.close();
            if (!error_occured) {
                int freq;
                for (size_t i = from; i <= to; i++) {
                    freq = data[i - from];
                    if (freq == 0)
                        missing.push_back(i);
                    else if(freq > 1)
                        duplicated.push_back({i, freq});
                }
            }
            delete[]data;
            return { duplicated, missing };
        }
        static int bin_srch(vector<int>& vec, int l, int r, int& target) {
            if (l > r)
                return -1;
            int m = l + (r - l) / 2;
            if (vec[m] == target)
                return m;
            else if (vec[m] > target)
                return bin_srch(vec, l, m - 1, target);
            else
                return bin_srch(vec, m + 1, r, target);

        }
        static bool clear_duplicatios(vector<int> duplicated_id, string file_name) {
            ifstream file(file_name);
            if (!file)
                return false;
            vector<string> data;
            string buffer;
            sort(duplicated_id.begin(), duplicated_id.end());
            bool* found = new bool[duplicated_id.size() + 1]{false};
            while (getline(file, buffer)){
                int id = convert_to_int(decription(buffer.substr(0, 6)));
                if (id <= duplicated_id[duplicated_id.size() - 1] && id >= duplicated_id[0]){
                    int tmp = bin_srch(duplicated_id, 0, duplicated_id.size() - 1, id);
                    if (tmp != -1) {
                        if (!found[tmp])
                            found[tmp] = true;
                        else
                            continue;
                    }
                }
                data.push_back(buffer);
            }
            delete[]found;
            file.close();
            ofstream new_file(file_name);
            if (!new_file)
                return false;
            for(auto &x : data)
                new_file << x << '\n';
            return true;
        }
        static void retrieve_data(vector<string> &names, string output_file_name) {
            ofstream dec_data(output_file_name, ios::app);
            if (file_is_empty(dec_data)) {
                if(output_file_name.find("Reports") != string::npos)
                    dec_data << "PC-ID,Report created at,Report created by,Damaged piece,Notes,Cost\n";
                else
                    dec_data << "PC-ID,PC assigned at,PC assigned by,Processor,RAM,Hard Disk,Motherboard,Monitor,Printer brand,Printer model\n";

            }
            ifstream enc_data;
            string data;
            int id;
            for (auto& n : names) {
                enc_data.open(n);
                if (!enc_data || !dec_data) {
                    MessageBox::Show("Error occured and data hasn't been saved! Make sure to close the (.mhm) and (.csv) files", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }
                while (getline(enc_data, data)){
                    id = convert_to_int(decription(data.substr(0, 6)));
                    dec_data << id << decription(data.substr(6), id) << '\n';
                }
                enc_data.close();
            }
            String^ str = gcnew String(("Data Displayed Successfuly in the file \'" + output_file_name + "\'").c_str());
            MessageBox::Show(str,"Successful Operation!", MessageBoxButtons::OK, MessageBoxIcon::Information);
            ofstream display_file("Reviewed_Data.csv", ios::app);
            if(!display_file)
                MessageBox::Show("Displayed file(s) hasn't been recorded in the file (Reviewed_Data.csv) because it was opened!", "WARNING!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            if (file_is_empty(display_file))
                display_file << "File name,Display time\n";
            size_t index = 0;
            for (auto& name : names) {
                index = 0;
                for (size_t i = name.size() - 1; i > 0 ; i--)
                    if (name[i] == '\\') {
                        index = i;
                        break;
                    }
                display_file << name.substr(index + 1) << ',' << WriteData::get_time() << '\n';
            }
            display_file.close();
        }
        static void merge_files(vector<string> files_name, string output_file_name) {
            ifstream single_file;
            for (auto& file : files_name) {
                single_file.open(file);
                ofstream comb_f(output_file_name);
                if (!comb_f || !single_file) {
                    MessageBox::Show("Error occured and files haven't been Merged!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }
                string data;
                while (getline(single_file, data))
                    comb_f << data << '\n';
                single_file.close();
            }
            String^ str = gcnew String(("Files Merged Successfuly in the file \'" + output_file_name + "\'").c_str());
            MessageBox::Show(str, "Successful Operation!", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    };
}