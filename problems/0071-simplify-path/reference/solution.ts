function simplifyPath(path: string): string {
    const parts: string[] = [];
    for (const part of path.split("/")) {
        if (part === "..") {
            parts.pop();
        } else if (part !== "" && part !== ".") {
            parts.push(part);
        }
    }
    return "/" + parts.join("/");
}
