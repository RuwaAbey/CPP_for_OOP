#include <iostream>
#include <vector>
#include <fstream>

class classRoomAirQuality
{
    public:

    classRoomAirQuality() = default;

    classRoomAirQuality(std::string _timestamp,	
        std::string _school_period, 
        int _student_count_estimated,
        double _co2_ppm,
        double _pm25_ugm3,
        double _temperature_c,
        double _humidity_pct,	
        double _robot_x_pos,	
        double _robot_y_pos,	
        std::string _ventilation_decision,
        std::string _air_quality_label)

        : timestamp(_timestamp),	
        school_period(_school_period), 
        student_count_estimated(_student_count_estimated),
        co2_ppm(_co2_ppm),
        pm25_ugm3(_pm25_ugm3),
        temperature_c(_temperature_c),
        humidity_pct(_humidity_pct),	
        robot_x_pos(_robot_x_pos),	
        robot_y_pos(_robot_y_pos),	
        ventilation_decision(_ventilation_decision),
        air_quality_label(_air_quality_label)
    {

    }
        std::string timestamp; 	//datetime 	Reading time (YYYY-MM-DD HH:MM:SS)
        std::string school_period; //string 	Active school period (1st Period, Break, etc.)
        int student_count_estimated; // 	int 	Estimated number of students in room
        double co2_ppm; //	float 	//CO₂ concentration (ppm)
        double pm25_ugm3; 	//float 	PM2.5 particulate matter (μg/m³)
        double temperature_c; //	float 	Room temperature (°C)
        double humidity_pct; 	//float 	Relative humidity (%)
        double robot_x_pos; 	//float 	Robot X position on 4×4 grid
        double robot_y_pos; 	//float 	Robot Y position on 4×4 grid
        std::string ventilation_decision; 	//string 	AI output: IDLE / MONITOR / ACTIVATE
        std::string air_quality_label; //	string 	Air quality class: Good / Moderate / Poor
};

bool tokenise(std::string csvLine, char seperator, classRoomAirQuality& room)
{
    signed int start, end;
    std::string token;
    std::vector<std::string> tokens;

    start = csvLine.find_first_not_of(seperator,0);

    do
    {
        end = csvLine.find(seperator,start);

        if (start == csvLine.length() || start == end) break;

        if (end >= 0) 
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }

        tokens.push_back(token);

        start = end +1;

    }while(end > 0);

    if(tokens.size() != 11)
    {
        std::cout << "Bad line!" << std::endl;
        return false;
    }

    try
    {
        int student_count_estimated = std::stoi(tokens[2]);
        double co2_ppm = std::stod(tokens[3]);
        double pm25_ugm3 = std::stod(tokens[4]);
        double temperature_c = std::stod(tokens[5]);
        double humidity_pct = std::stod(tokens[6]);
        double robot_x_pos = std::stod(tokens[7]);
        double robot_y_pos = std::stod(tokens[8]);
    }
    catch(std::exception& e)
    {
        std::cout << "Bad token" << std::endl;
        return false;
    }

    room = classRoomAirQuality
    {
        tokens[0],
        tokens[1],
        std::stoi(tokens[2]),
        std::stod(tokens[3]),
        std::stod(tokens[4]),
        std::stod(tokens[5]),
        std::stod(tokens[6]),
        std::stod(tokens[7]),
        std::stod(tokens[8]),
        tokens[9],
        tokens[10]
    };

    return true;

}

int main()
{
    std::ifstream csvFile{"unique_tech_classroom_air_quality.csv"};
    std::string line;
    std::vector<classRoomAirQuality> class_room_vector;

    int bad_count = 0;
    int good_count = 0;

   // line = "2025-11-12 08:00:00,Morning Entry,11,442.1,5.16,21.0,45.0,2.0,4.0,IDLE,Good";
   // class_room_vector.push_back(tokenise(line,','));

    if (csvFile.is_open())
    {
        std::cout << "File is open" << std::endl;

        std::getline(csvFile,line); //skip header line

        while(std::getline(csvFile,line))
        {
            classRoomAirQuality room;

            if (tokenise(line,',',room))
            {
                class_room_vector.push_back(room);
                good_count += 1;
            }
            else
            {
                std::cout << "Skipping Bad line" << std::endl;
                bad_count += 1;
            }
        }

        csvFile.close();
    }
    else
    {
        std::cout << "Could not open file" << std::endl;
    }
        

    for(unsigned int i = 0; i < class_room_vector.size(); ++i)
    {
       std::cout << "=============================" << std::endl;
       std::cout << "The timestamp is: " << class_room_vector[i].timestamp << std::endl;
       std::cout << "The school period is: " << class_room_vector[i].school_period << std::endl;
       std::cout << "Student count is: " << class_room_vector[i].student_count_estimated << std::endl;;
       std::cout << "CO2 ppm is: " << class_room_vector[i].co2_ppm << std::endl;
       std::cout << "PM25 UGM3 is: " << class_room_vector[i].pm25_ugm3 << std::endl; 	
       std::cout << "Temperature is: " << class_room_vector[i].temperature_c << std::endl; 
       std::cout << "Humidity is: " << class_room_vector[i].humidity_pct << std::endl; 	
       std::cout << "Robot x position is: " << class_room_vector[i].robot_x_pos << std::endl; 	
       std::cout << "Robot y position is: " << class_room_vector[i].robot_y_pos << std::endl; 	
       std::cout << "Ventilation decision is: " << class_room_vector[i].ventilation_decision << std::endl; 
       std::cout << "Air quality label is: " << class_room_vector[i].air_quality_label << std::endl; 
    }

    std::cout << "==========PRINT-STATISTICS==========" << std::endl;
    std::cout << "Number of valid lines: " << good_count << std::endl;
    std::cout << "Number of invalid lines: " << bad_count << std::endl;

    std::cout << "================END================" << std::endl;

}
