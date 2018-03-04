# 语音朗读助手

![img](https://github.com/yuezhihan/tts-software/blob/master/screenshot.png)

## 源代码编译注意事项

1. 要安装Microsoft Speech SDK，并注册其类库，才能正常编译。
2. /Vcl/中的utilcls.h并不属于工程源代码，而是对开发环境中一个VCL标准库的hack，编译前请先替换标准库。

## 软件内置标签教程

XML标签能够在朗读过程中控制音量、语速、音调、强调、拼读、停顿、音素、语音、词性等。本文介绍XML标签的使用方法，要启用XML标签功能，您应该确认您已经在“菜单-设置”中勾选了“打开标签解析器”。测试实例时，请选用正确的语音库，缺少语音库可以在“database”下安装。所有XML标签均可以在“菜单-XML标签”中找到，使用它们可以节省不少时间。

### 暂停标签（书签）

`<bookmark mark="书签名"/>`

定义一个书签后，当朗读到书签所在位置后，会“软暂停（即不会立刻暂停，可能会有短暂延迟）”当前朗读操作，当操作者手动按下开始后，才会继续朗读进程。

### 状态控制

注：在测试“实例”前请切换到英文语音库。

#### 音量

`<volume level="X">TEXT</volume>`（这是不为空的情况，下文会简写为类似`<volume level="X">`的格式）

Volume标签用于控制音量的大小。这个标签可以为空，这将会使它应用于所有的该标签后面的文本；它也可以有内容，这种情况应用于标签内的内容。注意X是音量大小，应是一个在0-100之间的整数（下文会用区间表示），要注意不要使用错误的格式，否则可能引发未知错误。

**什么是空标签**

这是一个内容为TEXT的书签：`<volume level="5">TEXT</volume>`

这是一个空书签（注意后面的/号）：`<volume level="5"/>`

在程序的XML菜单中，“volume空标签”是以“volume/”标示的，而建立“XML非空标签”应该先用“volume”，写好内容后，再用“/volume”，对比上面的代码，就很容易理解了。有的标签不能为空标签，则在XML菜单中不会有“标签名/”，通过XML菜单能找到所有的可用的标签的格式，非常方便！

**实例**

```
<volume level="50">
OK?
    <volume level="100">
    OK?
    </volume>
</volume>

<volume level="80"/>
OK?
OK?
```

#### 语速

`<rate absspeed="X">`和`<rate speed="X">`

Rate标签控制语速的快慢。当标签为空时，它将会作用于所有的该标签后面的文本；当它不为空时，它将会应用于标签内的内容。X∈[-10,10].AbsSpeed控制绝对语速。而Speed控制相对语速。

**实例**

```
<rate absspeed="5">
这个文本应该用速率5朗读。
<rate absspeed="-5">
OK?
</rate>
</rate>
<rate absspeed="10"/>
OK?
OK?
OK?
```

#### 音调

`<pitch absmiddle="X">`和`<pitch middle="X">``

Pitch标签控制音调的高低。当标签为空时，它将会作用于所有的该标签后面的文本；当它不为空时，它将会应用于标签内的内容。X∈[-10,10].AbsMiddle控制绝对音调。而Middle控制相对音调。

#### 强调

`<emph>`

Emph标签用于重读一段文字。此标签不能为空。

**实例**

```
OK?`<emph>`OK?`</emph>`OK?
```

#### 拼读

`<spell>`

Spell标签用于拼读一段文字。此标签不能为空。

**实例**

```
Hello!`<spell>` Hello`</spell>`Hello!
```


### 插入控制（在测试“·实例”前请切换到英文语音库）

#### 停顿

`<silence msec="X"/>`

Silence标签用于停顿。X为停顿的时间，单位为毫秒。该标签必须为空标签。

**实例**

```
Hello!<silence msec="1000"/>Hello.
```

#### 音素

`<pron sym="用空格分隔的音素">`

Pron 标签用于插入指定的音。程序将严格按照被指定的音素的顺序朗读。此标签可以为空，也可以不为空。如果它不为空的话，文本会被无视而按照音素朗读。

**实例**

```
<pron sym="h eh 1 l ow & w er 1 l d"> ~~~~(>_<)~~~~ 为什么读不到我，我被无视了... </pron>
```


### 读法控制（在测试“·实例”前请切换到中文语音库）

#### 语言

`<lang langid="X">`

Lang标签用于改变语言。当标签为空时，它将会作用于所有的该标签后面的文本；当它不为空时，它将会应用于标签内的内容。

**实例**

```
Hello.
<lang langid="409">
   Hello.
</lang>
```

#### 词性

`<partofsp part="词性">`

Partofsp标签用于分析词性。比如朗读某些专有名词，系统可能无法分析到它是个名词，您应该用这种方式指出它。词性可以为 "Noun", "Verb", "Modifier", "Function", "Interjection","Unknown"。

#### 格式

`<context id="date_mdy等">`

Context标签能让程序以确切的格式朗读文字，如货币、日期等。此标签不能为空。

**实例**

```
<context id="date_dmy"> 04/05/02 </context>
<context id="date_mdy"> 04/05/02 </context>
<context id="date_ymd"> 04/05/02 </context>
```
