#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <queue>

#ifdef _WIN32
#include <Windows.h>

void sleep(int ms) {
    sleep(ms);
}