#include <iostream>
#include <memory>
#include <string>
#include <queue>

#define TEST_LOCAL 0
#define TEST_GLOBAL 0
#define TEST_MAKE_LOCAL_SHARED 0
#define TEST_MAKE_GLOBAL_SHARED 1

class Student
{
public:
	Student(std::string name, int age) : m_name(name), m_age(age)
	{
		std::cout << "Student Constructor Name:" << m_name << ", Age:" << m_age << std::endl;
	}
	virtual ~Student()
	{
		std::cout << "Student Destructor Name:" << m_name << ", Age:" << m_age << std::endl;
	}

private:
	std::string m_name;
	int m_age;
};

std::queue<Student> g_Queue;
std::queue<std::shared_ptr<Student>> g_Student;

void AddStudent()
{
	std::cout << "\nTEST_GLOBAL--AddStudent()" << std::endl;
	Student student1("Jack", 22);
	std::cout << "DEBUG 1" << std::endl;
	g_Queue.push(student1);
	std::cout << "DEBUG 2" << std::endl;

	Student student2("Nancy", 24);
	std::cout << "DEBUG 3" << std::endl;
	g_Queue.push(student2);
	std::cout << "DEBUG 4" << std::endl;
}

void DeleteStudent()
{
	std::cout << "\nTEST_GLOBAL--DeleteStudent()" << std::endl;
	g_Queue.pop();
	std::cout << "DEBUG 5" << std::endl;

	g_Queue.pop();
	std::cout << "DEBUG 6" << std::endl;
}

void AddSharedStudent()
{
	std::cout << "\nTEST_MAKE_GLOBAL_SHARED--AddSharedStudent()" << std::endl;
	std::shared_ptr<Student> student1 = std::make_shared<Student>("Jack", 22);
	std::cout << "DEBUG 1" << std::endl;
	g_Student.push(student1);
	std::cout << "DEBUG 2" << std::endl;

	std::shared_ptr<Student> student2 = std::make_shared<Student>("Nancy", 24);
	std::cout << "DEBUG 3" << std::endl;
	g_Student.push(student2);
	std::cout << "DEBUG 4" << std::endl;
}

void DeleteSharedStudent()
{
	std::cout << "\nTEST_MAKE_GLOBAL_SHARED--DeleteSharedStudent()" << std::endl;
	g_Student.pop();
	std::cout << "DEBUG 5" << std::endl;

	g_Student.pop();
	std::cout << "DEBUG 6" << std::endl;
}

int main()
{

/*
 * 每个Student都构造1次，析构2次
 * [比使用XQueue包装后的queue少一次析构]
 * 
    TEST_LOCAL--AddStudent
    Student Constructor Name:Jack, Age:22
    DEBUG 1
    DEBUG 2
    Student Constructor Name:Nancy, Age:24
    DEBUG 3
    DEBUG 4

    TEST_LOCAL--DeleteStudent
    Student Destructor Name:Jack, Age:22
    DEBUG 5
    Student Destructor Name:Nancy, Age:24
    DEBUG 6
    1
    Student Destructor Name:Nancy, Age:24
    Student Destructor Name:Jack, Age:22
 */
#if TEST_LOCAL
	std::queue<Student> xQueue;
	std::cout << "\nTEST_LOCAL--AddStudent" << std::endl;
	Student student1("Jack", 22);
	std::cout << "DEBUG 1" << std::endl;
	xQueue.push(student1);
	std::cout << "DEBUG 2" << std::endl;

	Student student2("Nancy", 24);
	std::cout << "DEBUG 3" << std::endl;
	xQueue.push(student2);
	std::cout << "DEBUG 4" << std::endl;

	std::cout << "\nTEST_LOCAL--DeleteStudent" << std::endl;
	xQueue.pop();
	std::cout << "DEBUG 5" << std::endl;

	xQueue.pop();
	std::cout << "DEBUG 6" << std::endl;
#endif

/*
 * 每个Student都构造1次，析构2次
 * [比使用XQueue包装后的queue少一次析构]
 * 
    TEST_GLOBAL--AddStudent()
    Student Constructor Name:Jack, Age:22
    DEBUG 1
    DEBUG 2
    Student Constructor Name:Nancy, Age:24
    DEBUG 3
    DEBUG 4
    Student Destructor Name:Nancy, Age:24
    Student Destructor Name:Jack, Age:22

    TEST_GLOBAL--DeleteStudent()
    Student Destructor Name:Jack, Age:22
    DEBUG 5
    Student Destructor Name:Nancy, Age:24
    DEBUG 6
	1	//这里是getchar()的输入
 */
#if TEST_GLOBAL
	AddStudent();
	DeleteStudent();
#endif

/*
 * 每个Student都构造1次，析构1次(但是是在主函数结束时才释放，没有在Pop时释放)
 * [此结果同使用XQueue包装后的queue结果一样]
 * 
    TEST_MAKE_LOCAL_SHARED--AddLocalStudent
    Student Constructor Name:Jack, Age:22
    DEBUG 1
    DEBUG 2
    Student Constructor Name:Nancy, Age:24
    DEBUG 3
    DEBUG 4

    TEST_MAKE_LOCAL_SHARED--DeleteLocalStudent
    DEBUG 5
    DEBUG 6
	1	//这里是getchar()的输入
	Student Destructor Name:Nancy, Age:24
	Student Destructor Name:Jack, Age:22
 */
#if TEST_MAKE_LOCAL_SHARED
	std::queue<std::shared_ptr<Student>> xStudent;
	std::cout << "\nTEST_MAKE_LOCAL_SHARED--AddLocalStudent" << std::endl;
	std::shared_ptr<Student> student1 = std::make_shared<Student>("Jack", 22);
	std::cout << "DEBUG 1" << std::endl;
	xStudent.push(student1);
	std::cout << "DEBUG 2" << std::endl;

	std::shared_ptr<Student> student2 = std::make_shared<Student>("Nancy", 24);
	std::cout << "DEBUG 3" << std::endl;
	xStudent.push(student2);
	std::cout << "DEBUG 4" << std::endl;

	std::cout << "\nTEST_MAKE_LOCAL_SHARED--DeleteLocalStudent" << std::endl;
	xStudent.pop();
	std::cout << "DEBUG 5" << std::endl;

	xStudent.pop();
	std::cout << "DEBUG 6" << std::endl;
#endif

/*
 * 每个Student都构造1次，析构1次
 * [此结果同使用XQueue包装后的queue结果一样，在Pop时成功释放]
 * 
    TEST_MAKE_GLOBAL_SHARED--AddSharedStudent()
    Student Constructor Name:Jack, Age:22
    DEBUG 1
    DEBUG 2
    Student Constructor Name:Nancy, Age:24
    DEBUG 3
    DEBUG 4

    TEST_MAKE_GLOBAL_SHARED--DeleteSharedStudent()
    Student Destructor Name:Jack, Age:22
    DEBUG 5
    Student Destructor Name:Nancy, Age:24
    DEBUG 6
	1	//这里是getchar()的输入
 */
#if TEST_MAKE_GLOBAL_SHARED
	AddSharedStudent();
	DeleteSharedStudent();
#endif

	getchar();
	return 0;
}