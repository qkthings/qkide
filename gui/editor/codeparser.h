#ifndef CODEPARSER_H
#define CODEPARSER_H

#include <QObject>
#include <QThread>
class QTextDocument;
class QProcess;
class QTimer;

class CodeParser : public QObject
{
    Q_OBJECT
public:
    class Element
    {
    public:
        enum Type
        {
            Unknown = 0,
            Define,
            Enum,
            Function,
            Variable,
            Typedef
        };

        QString text;
        QString fileName;
        QString expression;
        Type type;
        bool local;
    };

    explicit CodeParser(QObject *parent = 0);

    QList<Element> allElements();
    QList<Element> functions() { return m_functions; }
    QList<Element> defines() { return m_defines; }
    QList<Element> enums() { return m_enums; }
    QList<Element> types() { return m_types; }
    QList<Element> variables() { return m_variables; }

signals:
    void parsed();

public slots:
    void parse(const QString &path);
    void clear();

private slots:


private:
    QList<Element> m_functions;
    QList<Element> m_defines;
    QList<Element> m_enums;
    QList<Element> m_types;
    QList<Element> m_variables;

};

class CodeParserThread : public QThread
{
    Q_OBJECT
public:
    explicit CodeParserThread(QObject *parent = 0);
    void setParserPath(const QString &path) { m_path = path; }
    CodeParser* parser() { return m_parser; }

protected:
    void run();

public slots:
    void startTimer();

private slots:
    void slotParse();
    void slotParsed();

signals:
    void parsed();

private:
    CodeParser *m_parser;
    QTimer *m_timer;
    QString m_path;
};

#endif // CODEPARSER_H