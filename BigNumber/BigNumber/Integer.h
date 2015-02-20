﻿#ifndef _BIG_INT_H_
#define _BIG_INT_H_

#include <vector>
#include <string>

class Integer
{
public:
	Integer();
	~Integer();
	Integer(int n);
	Integer(unsigned int n);
	explicit Integer(const std::string& n);
	Integer(const Integer& other);

	//사칙 연산
	const Integer add(const Integer& other) const;
	const Integer multiply(const Integer& other) const;
	const Integer divide(const Integer& other) const;
	const Integer mod(const Integer& other) const;

	//비교 연산 - 음수: 왼쪽이 작음 0: 동일 양수 : 오른쪽이 작음
	int compare(const Integer& other) const;

	//부호 변경
	const Integer signSwitch() const;
	//shift
	const Integer leftShift(unsigned int n) const;
	const Integer rightShift(unsigned int n) const;

	//부호 연산
	const Integer operator -() const;
	const Integer operator +() const;
	
	//사칙 연산
	const Integer operator +(const Integer& other) const;
	const Integer operator -(const Integer& other) const;
	const Integer operator *(const Integer& other) const;
	const Integer operator /(const Integer& other) const;
	const Integer operator %(const Integer& other) const;

	//비교 연산
	bool operator ==(const Integer& other) const;
	bool operator !=(const Integer& other) const;
	bool operator >(const Integer& other) const;
	bool operator >=(const Integer& other) const;
	bool operator <(const Integer& other) const;
	bool operator <=(const Integer& other) const;

	//비트 연산
	const Integer operator <<(unsigned int n) const;
	const Integer operator >>(unsigned int n) const;

	//대입 연산
	Integer& operator =(const Integer& other);
	Integer& operator +=(const Integer& other);
	Integer& operator -=(const Integer& other);
	Integer& operator *=(const Integer& other);
	Integer& operator /=(const Integer& other);
	Integer& operator %=(const Integer& other);
	Integer& operator <<=(unsigned int n);
	Integer& operator >>=(unsigned int n);
	
	void print() const;
	const std::string asString() const;
	bool isPositive() const;

private:
	inline unsigned int highWord(unsigned int n) const;
	inline unsigned int lowWord(unsigned int n) const;
	void divideWithRemainder(const Integer& divisor, const Integer& dividend,
								Integer* quot, Integer* rem, int bit) const;

	void stringToValue(const std::string& n);
	const std::string valueToString() const;
	void normalize();

	std::vector<unsigned int>		m_Value;
	bool							m_Positive;
};


//관련 전역 함수들
Integer abs(const Integer& integer);

//사칙연산
const Integer operator +(int n, const Integer& other);
const Integer operator -(int n, const Integer& other);
const Integer operator *(int n, const Integer& other);
const Integer operator /(int n, const Integer& other);
const Integer operator %(int n, const Integer& other);

#endif