#pragma once

enum returnValue {
	success = 0,
	ErrorCreateFile = 1,
	ErrorAddFile = 2,
	ls_execute_fail = 3,
	rm_execute_fail = 4,
	touch_execute_fail,
	cat_execute_fail,
	cat_user_quit,
	ds_execute_fail,
	cp_execute_fail,
	macro_parse_fail,
};

enum imageFileRV{
	empty_size = 100,
	bad_content,
	size_not_match,
	Image_cannot_append,
};

enum fileSystemRV{
	file_exists = 200,
	file_not_exists,
	null_pointer,
	invalid_extension,
	file_open
};

enum passwordProxyRV{
	ErrorPassword = 300,
};