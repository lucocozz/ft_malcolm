# ft_malcolm

```
while (1) {
	if (is_poisoned() == false)
		send_poisoned_arp_request();
	while (1) {
		if (recv_arp_request() != TIMEOUT)
			send_poisoned_arp_reply();
		else
			break ;
	}
}
```


## Sources
https://www.rfc-editor.org/rfc/rfc826  
https://fr.wikipedia.org/wiki/EtherType  
https://www.youtube.com/watch?v=16VO0wc8HfM  
https://www.imperva.com/learn/application-security/arp-spoofing/  
http://blog.zorinaq.com/a-more-powerful-stealthier-and-uncommon-arp-poisoning-technique/  
https://manpages.ubuntu.com/manpages/trusty/man5/etter.conf.5.html  
https://linuxconfig.org/how-to-turn-on-off-ip-forwarding-in-linux  
https://github.com/byt3bl33d3r/arpspoof/blob/master/arpspoof/arpspoof.py  
https://man7.org/linux/man-pages/man7/packet.7.html