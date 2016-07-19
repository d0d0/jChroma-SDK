![Razer Chroma SDK](http://developer.razerzone.com/wp-content/uploads/works-with-razer-chroma.png)
# jChroma SDK
Unofficial Java wrapper for Razer Chroma SDK

Installation
------------
Add to your `pom.xml` file
```xml
<repositories>
    <repository>
        <id>jChroma-SDK</id>
        <url>https://raw.github.com/D0d0/jChroma-SDK/mvn-repo/</url>
        <snapshots>
            <enabled>true</enabled>
            <updatePolicy>always</updatePolicy>
        </snapshots>
    </repository>
</repositories>

<dependency>
    <groupId>com.jChroma</groupId>
    <artifactId>jChroma-SDK</artifactId>
    <version>0.4-SNAPSHOT</version>
</dependency>
```

Usage
-----
First we must create and initialize Chroma object
```java
Chroma chroma = Chroma.getInstance();
```

Chroma object can access devices. To access Mousemat device use
```java
chroma.getMousemat();
```
Now you can change effects on mousemat.

Testing effects
---------------
You can test effects by running test files.
