//Name: Gagan Gupta 
//Date: 10/01/20
//Title: COEN 146L Lab 2 - Part 2
//Description: Testing Network commands and doing time calculation comparisons for various HTTP methods 

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

#define RTT0 3
#define RTT1 20
#define RTT2 26
#define RTTHTTP 47

void step2(){
	system("netstat -a");
	sleep(2);
	system("ifconfig -a");
	sleep(2);
	system("hostname");
	sleep(2);
	system("ping www.cnn.com -c 5");
	sleep(2);
	system("traceroute www.cnn.com");
	sleep(2);
	system("telnet 192.168.1.1 443");
	sleep(2);
	system("host www.cnn.com");
	sleep(2);
	system("dig");
	sleep(2);
	system("route");
	sleep(2);
	system("arp");
	sleep(2);
}

void step3(){
	system("echo Pinging North America");
	system("ping www.cnn.com -c 3 -s 32");
	system("ping www.cnn.com -c 3 -s 524");
	system("ping www.cnn.com -c 3 -s 1048");
	sleep(2);
	system("echo Pinging Asia");
	system("ping baidu.com -c 3 -s 32");
	system("ping baidu.com -c 3 -s 524");
	system("ping baidu.com -c 3 -s 1048");
	sleep(2);
	system("echo Pinging Europe");
	system("ping www.giz.de -c 3 -s 32");
	system("ping www.giz.de -c 3 -s 524");
	system("ping www.giz.de -c 3 -s 1048");
	sleep(2);
	
// Pinging North America
// PING turner-tls.map.fastly.net (151.101.189.67) 32(60) bytes of data.
// 40 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=1 ttl=58 time=14.9 ms
// 40 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=2 ttl=58 time=14.9 ms
// 40 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=3 ttl=58 time=14.9 ms

// --- turner-tls.map.fastly.net ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2002ms
// rtt min/avg/max/mdev = 14.905/14.907/14.908/0.001 ms
// PING turner-tls.map.fastly.net (151.101.189.67) 524(552) bytes of data.
// 532 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=1 ttl=58 time=15.2 ms
// 532 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=2 ttl=58 time=15.4 ms
// 532 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=3 ttl=58 time=15.1 ms

// --- turner-tls.map.fastly.net ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2002ms
// rtt min/avg/max/mdev = 15.196/15.303/15.443/0.103 ms
// PING turner-tls.map.fastly.net (151.101.189.67) 1048(1076) bytes of data.
// 1056 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=1 ttl=58 time=15.4 ms
// 1056 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=2 ttl=58 time=15.4 ms
// 1056 bytes from 151.101.189.67 (151.101.189.67): icmp_seq=3 ttl=58 time=15.5 ms

// --- turner-tls.map.fastly.net ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2002ms
// rtt min/avg/max/mdev = 15.445/15.474/15.509/0.026 ms
// Pinging Asia
// PING baidu.com (220.181.38.148) 32(60) bytes of data.
// 40 bytes from 220.181.38.148 (220.181.38.148): icmp_seq=2 ttl=48 time=186 ms
// 40 bytes from 220.181.38.148 (220.181.38.148): icmp_seq=3 ttl=48 time=188 ms

// --- baidu.com ping statistics ---
// 3 packets transmitted, 2 received, 33% packet loss, time 2001ms
// rtt min/avg/max/mdev = 186.835/187.462/188.090/0.762 ms
// PING baidu.com (220.181.38.148) 524(552) bytes of data.
// 532 bytes from 220.181.38.148 (220.181.38.148): icmp_seq=1 ttl=48 time=187 ms
// 532 bytes from 220.181.38.148 (220.181.38.148): icmp_seq=2 ttl=48 time=187 ms
// 532 bytes from 220.181.38.148 (220.181.38.148): icmp_seq=3 ttl=48 time=188 ms

// --- baidu.com ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2001ms
// rtt min/avg/max/mdev = 187.129/187.613/188.070/0.522 ms
// PING baidu.com (39.156.69.79) 1048(1076) bytes of data.
// 1056 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=1 ttl=43 time=213 ms
// 1056 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=3 ttl=43 time=213 ms

// --- baidu.com ping statistics ---
// 3 packets transmitted, 2 received, 33% packet loss, time 2002ms
// rtt min/avg/max/mdev = 213.000/213.190/213.381/0.499 ms
// Pinging Europe
// PING www.giz.de (193.97.170.57) 32(60) bytes of data.
// 40 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=1 ttl=109 time=163 ms
// 40 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=2 ttl=109 time=161 ms
// 40 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=3 ttl=109 time=159 ms

// --- www.giz.de ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2001ms
// rtt min/avg/max/mdev = 159.814/161.555/163.454/1.560 ms
// PING www.giz.de (193.97.170.57) 524(552) bytes of data.
// 532 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=1 ttl=109 time=161 ms
// 532 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=2 ttl=109 time=160 ms
// 532 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=3 ttl=109 time=160 ms

// --- www.giz.de ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2000ms
// rtt min/avg/max/mdev = 160.503/160.727/161.173/0.559 ms
// PING www.giz.de (193.97.170.57) 1048(1076) bytes of data0.
// 1056 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=1 ttl=109 time=161 ms
// 1056 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=2 ttl=109 time=161 ms
// 1056 bytes from vm-topas.giz.de (193.97.170.57): icmp_seq=3 ttl=109 time=160 ms

// --- www.giz.de ping statistics ---
// 3 packets transmitted, 3 received, 0% packet loss, time 2001ms
// rtt min/avg/max/mdev = 160.933/161.095/161.315/0.161 ms
}

int timeCalc(int c){
  int nObjects=7;
  return (RTT0+RTT1+RTT2+ RTTHTTP*2*(ceil(nObjects/c)));
}

void step4(){
	printf("Client clicks on the link until the client receives the object: %d msecs\n",(RTT0+RTT1+RTT2+RTTHTTP*2));
	printf("Client clicks on the link until the base object and all 6 additional objects are received from web server at the client: %d msecs\n",(RTT0+RTT1+RTT2+RTTHTTP*14));
	printf("n parallel persistent connections: %d msecs\n", (RTT0+RTT1+RTT2+RTTHTTP*3));
	printf("2 parallel non-persistent connections: %d msecs\n", timeCalc(2));
	printf("3 parallel non-persistent connections: %d msecs\n", timeCalc(3)); 
	printf("4 parallel non-persistent connections: %d msecs\n", timeCalc(4)); 
	printf("5 parallel non-persistent connections: %d msecs\n", timeCalc(5)); 
	printf("6 parallel non-persistent connections: %d msecs\n", timeCalc(6)); 
	printf(">6 parallel non-persistent connections: %d msecs\n", timeCalc(7)); 
}

int main(){
	printf("Step 2: \n");
	step2();
	printf("Step 3: \n");
	step3();
	printf("Step 4: \n");
	step4();
}