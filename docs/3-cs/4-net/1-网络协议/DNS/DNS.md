# DNS

## 0. References

-   [Domain Name/DNS Resolution — How it Works?](https://cabulous.medium.com/domain-name-dns-resolution-how-it-works-bddafa0246ed)
-   [DNS Message — How to Read Query and Response Message](https://cabulous.medium.com/dns-message-how-to-read-query-and-response-message-cfebcb4fe817)

## 1. `nslookup`

???+ quote "`cheat.sh/nslookup`"

    ``` sh title="nslookup" linenums="1" hl_lines="4 7-8 10-11"
    $ curl cheat.sh/nslookup
    
    # nslookup
    # Query name server(s) for various domain records.
    # More information: <https://manned.org/nslookup>.
    
    # Query your system's default name server for an IP address (A record) of the domain:
    nslookup example.com
    
    # Query a given name server for a NS record of the domain:
    nslookup -type=NS example.com 8.8.8.8
    
    # Query for a reverse lookup (PTR record) of an IP address:
    nslookup -type=PTR 54.240.162.118
    
    # Query for ANY available records using TCP protocol:
    nslookup -vc -type=ANY example.com 
    
    # Query a given name server for the whole zone file (zone transfer) of the domain using TCP protocol:
    nslookup -vc -type=AXFR example.com name_server
    
    # Query for a mail server (MX record) of the domain, showing details of the transaction:
    nslookup -type=MX -debug example.com
    
    # Query a given name server on a specific port number for a TXT record of the domain:
    nslookup -port=port_number -type=TXT example.com name_server
    
    $
    ```

``` sh title="the basic `nslookup` command" hl_lines="1" linenums="1"
$ nslookup www.nyu.edu
Server:		192.168.31.1
Address:	192.168.31.1#53

Non-authoritative answer:
www.nyu.edu	canonical name = d1q5ku5vnwkd2k.cloudfront.net.
Name:	d1q5ku5vnwkd2k.cloudfront.net
Address: 18.164.174.32
Name:	d1q5ku5vnwkd2k.cloudfront.net
Address: 18.164.174.2
Name:	d1q5ku5vnwkd2k.cloudfront.net
Address: 18.164.174.128
Name:	d1q5ku5vnwkd2k.cloudfront.net
Address: 18.164.174.96
```



