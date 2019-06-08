typedef struct {
		int type;
		union {
			int _int;
			double _real;
			int _bool;
			char * _str;
			void * _ptr;
		};
} TOKEN;
