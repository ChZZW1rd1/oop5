#pragma once
#include <iostream>
using namespace std;

class Post
{
	string _title;
	string _text;
public:

	void SetTitle(string title)
	{
		_title = title;
	}
	void SetText(string text)
	{
		_text = text;
	}

	string GetTitle() { return _title; }
	string GetText() { return _text; }

	Post(string title, string text)
	{
		SetTitle(title);
		SetText(text);
	}
};

//////////////////////// User - обычный пользователь
class User
{
	int _id;
	string _login;
	string _password;
public:
	void SetId(int id)
	{
		_id = id;
	}
	void SetLogin(string login)
	{
		char arr[10] = { '{', '}', '<', '>', '@', '#', '$', '%', '^', '*'};
		for (int i = 0; i < login.length(); i++) {
			for (int j = 0; j < 10; j++) {
				if (login[i] == arr[j]) {
					throw exception("Incorrect login");
				}
			}
		}
		_login = login;
	}
	void SetPassword(string password)
	{
		_password = password;
	}
	int GetId() { return _id; }
	string GetLogin() { return _login; }
	string GetPassword() { return _password; }
	User(int id, string login, string password)
	{
		SetId(id);
		SetLogin(login);
		SetPassword(password);
	}
	bool IsCorrectPassword(string password)
	{
		return (password == _password);
	}
};

//////////////////////// Paid User - пользователь с платным аккаунтом
class PaidUser : public User 
{
	Post* _posts;
	int _postsCount;
public:

	void SetPosts(Post* posts, int postsCount)
	{
		if (postsCount < 0)
		{
			throw exception("Posts count must be more than 0");
		}
		_posts = posts;
		_postsCount = postsCount;
	}
	Post* GetPosts() { return _posts; }
	int GetPostsCount() { return _postsCount; }
	PaidUser(int id, string login, string password, Post* posts, int postsCount) : User(id, login, password)
	{
		SetPosts(posts, postsCount);
	}
	PaidUser(int id, string login, string password) :
		PaidUser(id, login, password, nullptr, 0)
	{
	}
};

User* Login(User** users, int usersCount, string enteredLogin, string enteredPassword)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->GetLogin() == enteredLogin)
		{
			if (users[i]->IsCorrectPassword(enteredPassword))
			{
				return users[i];
			}
			else
			{
				throw exception("Incorrect password");
			}
		}
	}
	return nullptr;
}


