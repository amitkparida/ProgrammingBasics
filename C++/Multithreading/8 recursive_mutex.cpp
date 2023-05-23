
//Recursive Mutex / Reentrant mutex: 
// A thread can acquire ownership of a mutex object that it already owns (recursive ownership), 
// but a recursively acquired mutex object is not set to the Signaled state until the thread releases 
// its ownership completely. Such a thread must explicitly release the mutex as many times as it acquired 
// ownership before another thread can acquire the mutex.

// Below code is example of cursive mutex usage. Single thread acquires the same mutex twice recursively 
// without causing a deadlock.

/*
void Fun1() {
	mtx.lock();
	Fun2();
	mtx.unlock();
}
void Fun2() {
	mtx.lock();
	//some code
	mtx.unlock();
}
*/
