#include <stdio.h>

#include <json_tokener.h>

int main() {
	
	const char * json_txt =
		"{ "
			"\"name\" : \"isel-leic-psc\","
			"\"year\" : 2019,"
			"\"students\" : [ 19723, 20000 ]"
		"}";

	struct json_object* json_obj;
	
	json_obj = json_tokener_parse(json_txt);

	const char * str =
		json_object_to_json_string_ext(
			json_obj,
			JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY
		);
		
	puts(str);

	struct json_object* students;
	
	if (json_object_object_get_ex (json_obj, "students", &students)) {
		int numStudents = json_object_array_length(students);
		printf("Number of students: %d\n", numStudents);
		if (numStudents > 0) {
			struct json_object* firstStudent = json_object_array_get_idx (students, 0);
			int number = json_object_get_int(firstStudent);
			printf("student: %d\n", number);
		}
	}
	
	json_object_put(json_obj);
}
