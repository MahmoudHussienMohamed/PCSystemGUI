#pragma once
    namespace PCSystemGUI {
    using namespace std;
    class WriteData
    {
    private:
        static string encription(string data, int id = 987654328) {
            id -= 32;
            string encrepted_data;
            for (auto x : data)
                encrepted_data += char(32 + (x + id) % 95);
            return encrepted_data;
        }
        static int convert_to_int(string s) {
            int id = 0;
            for (auto& x : s) {
                id *= 10;
                id += (x - '0');
            }
            return id;
        }
    public:
        static string get_time() {
            map <string, string> month{
                {"Jan", "01"},
                {"Feb", "02"},
                {"Mar", "03"},
                {"Apr", "04"},
                {"May", "05"},
                {"Jun", "06"},
                {"Jul", "07"},
                {"Aug", "08"},
                {"Sep", "09"},
                {"Oct", "10"},
                {"Nov", "11"},
                {"Dec", "12"}
            };
            time_t now = time(0);
            char* t = ctime(&now);
            string current_month;
            for (int i = 4; i < 7; i++)
                current_month.push_back(t[i]);
            current_month = month[current_month];
            string date;
            for (int i = 20; i < 24; i++)
                date.push_back(t[i]);
            date += "-" + current_month + "-";
            date.push_back(t[8] < '0' || t[8] > '9' ? '0' : t[8]);
            date.push_back(t[9]);
            date += " - ";
            for (int i = 11; i < 19; i++)
                date.push_back(t[i]);
            return date;
        }
        static bool write_data(string current_user, string file_name, string data)
        {
            int id = convert_to_int(data.substr(0, 6));
            ofstream data_base_file;
            file_name = current_user.substr(0, current_user.find('_') + 1) + get_time().substr(0, 10) + "_" + file_name + ".mhm";
            data_base_file.open(file_name, ios::app);
            if (!data_base_file) {
                return false;
            }
            data = data.substr(0, 6) + "," + get_time() + "," + current_user + data.substr(6);
            data_base_file << encription(data.substr(0, 6));
            data_base_file << encription(data.substr(6), id) << '\n';
            data_base_file.close();
            return true;
        }
        static bool edit_data(string file_name, vector<string> data, int edited_data)
        {
            ofstream edited_file(file_name);
            if (!edited_file) {
                return false;
            }
            for (size_t i = 0; i < data.size(); i++) {
                if(i != edited_data)
                    edited_file << data[i];
                else {
                    string str_id = data[i].substr(0, 6);
                    int id = convert_to_int((str_id));
                    edited_file << encription(str_id) << encription(data[i].substr(6), id);
                }
                edited_file << '\n';
            }
            edited_file.close();
            return true;
        }
    };
    
}